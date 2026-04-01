class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret=0;
        int l=0,r=1;
        int n = prices.size();
        if(n==1)return 0;
        while(r<n){
            if(prices[r] <= prices[l]){
                l = r;
            }
            else{
                ret = max(ret,prices[r] - prices[l]);
            }
            r++;
        }
        return ret;

    }
};
