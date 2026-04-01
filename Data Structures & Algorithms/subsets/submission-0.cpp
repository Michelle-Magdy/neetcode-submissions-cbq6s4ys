class Solution {
  
   
    void dfs(int i,vector<int> subset, vector<vector<int>>& res,vector<int>& nums){
        int n = nums.size();
        if(i >= n ) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1,subset,res,nums);

        subset.pop_back();
        dfs(i+1,subset,res,nums);
    
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
          vector<vector<int>> res;
        dfs(0,subset,res,nums);
        return res;    
    }
};
