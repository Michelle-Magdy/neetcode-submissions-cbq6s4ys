class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numSet(nums.begin(),nums.end());
       int ret =0;
       for(int num: nums){
        int curr = num,streak =1;
        if(numSet.find(num-1) == numSet.end()){
            while(numSet.find(curr +1) != numSet.end()){
                curr++;
                streak++;
            }
        }
        ret = max(ret,streak);
       } 
       return ret;
    }
};
