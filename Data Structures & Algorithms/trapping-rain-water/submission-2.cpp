class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(!n) return 0;
        int l=0,r=n-1;
        int res=0;
        int maxl=height[l],maxr = height[r];
        while(l<r){
            if(maxl  <= maxr){
                maxl = max(maxl,height[++l]);
                res += maxl - height[l];
            }else{
                maxr = max(maxr,height[--r]);
                res+= maxr - height[r];
            }   
        }
        return res;
    }
};
