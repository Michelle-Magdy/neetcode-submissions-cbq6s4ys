class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r = 1;
        int maxP =0;
        while(r < prices.size()){
            if(prices[r] < prices[l])l =r;
            else{
                maxP = max(maxP,prices[r] - prices[l]);
            }
            r++;
        }
        return maxP;
    }
};
