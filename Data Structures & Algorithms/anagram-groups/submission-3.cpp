class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string s: strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            hash[temp].push_back(s);
        } 
        vector<vector<string>> ret;
        for(auto it= hash.begin();it != hash.end();it++){
            vector<string> store;
            for(string s: it->second){
                store.push_back(s);
            }
            ret.push_back(store);
        }

        return ret;
    }
};
