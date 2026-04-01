class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resIndex =0,resLength =0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i = n-1;i>=0 ;i --){
            for(int j = i;j<n;j++){
                if(s[i] == s[j] && (j - i +1 <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(resLength < (j - i + 1)){
                        resLength = j - i + 1;
                        resIndex = i;
                    }
                }
            }
        }

        return s.substr(resIndex,resLength);
    }
};
