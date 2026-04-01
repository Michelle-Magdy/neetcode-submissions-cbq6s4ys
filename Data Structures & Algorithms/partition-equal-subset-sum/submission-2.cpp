class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum %2) return false;
        int target = sum /2;
        int n = nums.size();
        unordered_map<int,bool> dp;

        dp[0] = true;
        for(int i =0;i<nums.size();i++){
            unordered_map<int,bool> nextDp;
            for(auto e :dp){
                nextDp[e.first] = true;
                nextDp[e.first + nums[i]] =true;
            }
            swap(dp,nextDp);
        }
        return dp[target];

    }
    // 0 true 
};
