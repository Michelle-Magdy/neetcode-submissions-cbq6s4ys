class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r = heights.size()-1,maxH=0,curr=0;
        while(l<r){
            curr = (r-l) * min(heights[r],heights[l]);
            maxH = max(curr,maxH);
            if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }
        }

        return maxH;
    }
};
