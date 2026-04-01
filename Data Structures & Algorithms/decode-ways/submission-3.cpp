class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] =='0') return 0;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1;i<n;i++){
            if(s[i] == '0' && s[i-1]=='0' || (s[i]=='0' && (stoi(string() + s[i-1] + s[i])) >= 27)) return 0;
            if( (stoi(string() + s[i-1] + s[i])) >= 27 || s[i] =='0' || s[i-1] =='0' || (i+1 <n && s[i+1]=='0')) {
                dp[i+1] = dp[i];
            }else 
            {
                dp[i+1] = dp[i-1] + dp[i];
            }
        } 
        return dp[n];
    }
};
