class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i: nums){
            count[i]++;
        }
        vector<pair<int,int>> res;
        for(const auto& i:count){
            res.push_back({i.second,i.first});
        }

        sort(res.rbegin(),res.rend());
        vector<int> ret;
        for(int i=0;i<k;i++){
            ret.push_back(res[i].second);
        }
        return ret;

    }
};
