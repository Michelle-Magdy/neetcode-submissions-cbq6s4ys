class Solution {
private:
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
        dfs(nums,target,tempVal + nums[i],i,comb);
        comb.pop_back();
        dfs(nums,target,tempVal,i+1,comb);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        dfs(nums,target,0,0,temp);
        return res;
    }
};
