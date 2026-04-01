class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        // dp[i][0]: max profit on day i holding no stock
        // dp[i][1]: max profit on day i holding stock
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base cases
        dp[0][0] = 0;           // No stock on day 0
        dp[0][1] = -prices[0];  // Buy on day 0
        
        for (int i = 1; i < n; i++) {
            // Not holding stock: either sold today or didn't hold yesterday
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            
            // Holding stock: either bought today or held yesterday
            // If buying today, must have cooldown from i-2
            if (i >= 2) {
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            } else {
                dp[i][1] = max(dp[i-1][1], -prices[i]);
            }
        }
        
        return dp[n-1][0];
    }
};