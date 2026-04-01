class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.length()+1,vector<int>(s.length()+1,0));
       
        for(int j=0;j<=s.length();j++){
            dp[t.length()][j] = 1;
        }
        for(int i=t.length()-1;i>=0;i--){
            for(int j=s.length()-1;j>=0;j--){
                dp[i][j] = dp[i][j+1];
                if(t[i] == s[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
