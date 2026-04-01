class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum %2) return false;
        int target = sum /2;
        int n = nums.size();
        set<int> dp;

        dp.insert(0);
        for(int i =0;i<nums.size();i++){
            set<int> nextDp;
            for(int e:dp){
                nextDp.insert(e);
                nextDp.insert(e + nums[i]);
            }
            swap(dp,nextDp);
        }
        return dp.find(target) != dp.end();

    }
};
