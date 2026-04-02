class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums,int i,vector<int> temp){
        if(i >= nums.size()){
            res.emplace_back(temp);
            return;
        }

        temp.emplace_back(nums[i]);
        dfs(nums,i+1,temp);
        
        temp.pop_back();
        while(i+1 <nums.size() && nums[i] == nums[i+1]) i++;
        dfs(nums,i+1,temp);
    }    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0,{});
        return res;
    }
};
