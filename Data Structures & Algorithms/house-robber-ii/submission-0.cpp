class Solution {
    private:
    int helper(vector<int> nums){
        int n = nums.size();
        vector<int> dp(n+2);
        dp[1] = nums[0];
        for(int i = 2;i<=n;i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[(n+ i-1)%n]);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(helper(vector<int>(nums.begin() + 1, nums.end())),
                helper(vector<int>(nums.begin(), nums.end() - 1)));
    }
};
