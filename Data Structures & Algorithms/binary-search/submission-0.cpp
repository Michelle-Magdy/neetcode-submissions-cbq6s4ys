class Solution {
public:
    int search(vector<int>& nums, int target) {
        return (lower_bound(nums.begin(),nums.end(),target) == nums.end()  || *lower_bound(nums.begin(),nums.end(),target) != target)? -1: lower_bound(nums.begin(),nums.end(),target) - nums.begin(); 
    }
};
