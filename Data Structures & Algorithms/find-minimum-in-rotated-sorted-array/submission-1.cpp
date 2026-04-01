class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int first = nums[0],last = nums[n-1];
        if(first < last) return first;
        int l =1,r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] < nums[m-1]){
                return nums[m];
            }else if(nums[m] > last){
                l = m +1;
            }else {
                r = m -1;
            }
        }
        return nums[0];
        
    }
};
