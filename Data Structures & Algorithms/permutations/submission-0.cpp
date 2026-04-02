class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> temp,vector<int>& nums,int mask){
        if(temp.size() == nums.size()){
            res.emplace_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mask & (1 << i))continue;
            temp.emplace_back(nums[i]);
            dfs(temp,nums,mask | (1<<i));
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs({},nums,0);
        return res;
    }
};
