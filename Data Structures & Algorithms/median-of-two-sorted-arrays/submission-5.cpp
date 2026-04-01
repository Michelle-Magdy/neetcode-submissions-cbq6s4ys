class Solution {
public:
    bool can(int x,vector<int>& nums1, vector<int>& nums2){
        // This function appears unused in the median problem
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;  // 🔥 FIXED: use (total+1)/2 for correct partitioning
        if (B.size() < A.size()) {
            swap(A, B);
        }
        int l = 0, r = A.size();  // 🔥 FIXED: allow full range including empty partition
        while (l <= r) {
            int m1 = l + (r - l) / 2;  // number of elements to take from A
            int m2 = half - m1;  // number of elements to take from B
            int Al = (m1 > 0) ? A[m1 - 1] : INT_MIN;  // last element of A's left partition
            int Ar = (m1 < A.size()) ? A[m1] : INT_MAX;  // first element of A's right partition
            int Bl = (m2 > 0) ? B[m2 - 1] : INT_MIN;  // last element of B's left partition  
            int Br = (m2 < B.size()) ? B[m2] : INT_MAX;  // first element of B's right partition
            if (Al <= Br && Bl <= Ar) {
                if (total % 2) {
                    return max(Al, Bl);  // 🔥 FIXED: for odd, return max of left partition
                } else {
                    return (max(Al, Bl) + min(Ar, Br)) / 2.0;
                }
            } else if (Al > Br) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
        }
        return -1;
    }
};