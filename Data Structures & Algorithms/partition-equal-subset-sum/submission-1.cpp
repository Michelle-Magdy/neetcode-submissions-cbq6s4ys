class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum %2) return false;
        int target = sum /2;
        int n = nums.size();
        vector<int> dp;

        dp.push_back(0);
        for(int i =0;i<nums.size();i++){
            vector<int> nextDp;
            for(int e:dp){
                nextDp.push_back(e);
                nextDp.push_back(e + nums[i]);
            }
            swap(dp,nextDp);
        }
        return find(dp.begin(),dp.end(),target) != dp.end();

    }
};
