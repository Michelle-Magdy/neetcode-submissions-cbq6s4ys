class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int first = nums[0],last = nums[n-1];
        if(first < last){
            int indx =  lower_bound(nums.begin(),nums.end(),target) - nums.begin();
            return (nums[indx] == target)? indx : -1;
        }
        int l =0,r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;
            if(nums[l] <= nums[m]){
                if(target < nums[m] && target >= nums[l]) r = m -1;
                else l = m +1;
            }else {
                if(target > nums[m] && target <= nums[r]) l = m +1;
                else r = m - 1;
            }
        }
        return -1;
    }
};

