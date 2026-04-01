class Solution {
    vector<vector<int>> res;
    void dfs(vector<int>& nums,int target,int tempVal,int i,vector<int>& comb){
        if(target == tempVal){
            res.push_back(comb);
            return;
        }
        if(i >= nums.size() || target < tempVal){
            return;
        }
        comb.push_back(nums[i]);
        dfs(nums,target,tempVal + nums[i],i+1,comb);
        comb.pop_back();
        while(nums[i]==nums[i+1])i++;
        dfs(nums,target,tempVal,i+1,comb);
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        dfs(candidates,target,0,0,temp);
        return res;
        
    }
};
