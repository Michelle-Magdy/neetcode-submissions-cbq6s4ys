class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dp[i] = max(dp[i-1],dp[i-1] * nums[i])
        // 1 2 -3 4
        // dp[]
        // 1 2 -6 4 
        int n=nums.size();
        int curMin = 1,curMax = 1, ans=nums[0];
        for(int num:nums){
            int temp = curMax *num;
            curMax = max(num,max(num * curMin,num * curMax));
            curMin = min(num,min(num * curMin,temp));
            ans = max(ans,curMax);
        }
        return ans;


    }
};

