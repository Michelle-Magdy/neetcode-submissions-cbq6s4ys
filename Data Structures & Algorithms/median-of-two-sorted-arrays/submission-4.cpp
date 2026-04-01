class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = total / 2;
        if (B.size() < A.size()) {
            swap(A, B);
        }
        int l = 0, r = A.size();   // allow partition after last element
        while (true) {
            int m1 = l + (r - l) / 2;
            int m2 = half - m1;
            int Al = (m1 - 1 >= 0) ? A[m1 - 1] : INT_MIN;
            int Ar = (m1 < A.size()) ? A[m1] : INT_MAX;
            int Bl = (m2 - 1 >= 0) ? B[m2 - 1] : INT_MIN;
            int Br = (m2 < B.size()) ? B[m2] : INT_MAX;
            if (Al <= Br && Bl <= Ar) {
                if (total % 2) {
                    return min(Ar, Br);  // 🔥 FIXED: return min of right elements for odd total
                } else {
                    return (max(Al, Bl) + min(Ar, Br)) / 2.0;  // correct for even total
                }
            } else if (Al > Br) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
        }
    }
};