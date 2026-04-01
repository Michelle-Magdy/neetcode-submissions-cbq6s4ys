class Solution {
public:
    bool can(int k ,vector<int>& piles, int h){
        int nhours = 0;
        for(int b:piles){
            nhours += (b + k - 1)/ k;
        }
        return nhours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans =0;
        int l =1 ,r = 1e9 +5;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(can(mid,piles,h)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
};
