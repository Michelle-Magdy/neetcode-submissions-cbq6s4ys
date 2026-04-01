class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s: strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c -'a']++;
            }
            string hash="";
            for(int i:count){
                hash+=char(i);
            }
            m[hash].push_back(s);
        } 
        vector<vector<string>> ret;
        for(auto it= m.begin();it != m.end();it++){
            vector<string> store;
            for(string s: it->second){
                store.push_back(s);
            }
            ret.push_back(store);
        }

        return ret;
    }
};
