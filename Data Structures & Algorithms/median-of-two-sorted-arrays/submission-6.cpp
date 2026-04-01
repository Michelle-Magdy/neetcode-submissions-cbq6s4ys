class Solution {
public:
    bool can(int x,vector<int>& nums1, vector<int>& nums2){

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total+1) /2;
        if (B.size() < A.size()) {
            swap(A, B);
        }
        int l = 0,r = A.size();
        while(l <= r){
            int m1 = l + (r - l)/2; // 0
            int m2 = half - m1 ;// min
            int Al = (m1 -1 >=0)? A[m1 -1]: INT_MIN; // 3
            int Ar = (m1 < A.size())? A[m1]:INT_MAX;// max
            int Bl = (m2 - 1 >= 0)? B[m2 - 1] : INT_MIN; // min
            int Br = (m2 < B.size())? B[m2]:INT_MAX; // max
            if(Al <= Br && Bl <= Ar){
                if(total % 2){
                    return max(Al,Bl);
                }else{
                    return (max(Al,Bl) + min(Br,Ar)) /2.0;
                }
            }else if(Al > Br){
                r = m1 -1;
            }else l = m1 +1;
        }
        return -1;
    }
};