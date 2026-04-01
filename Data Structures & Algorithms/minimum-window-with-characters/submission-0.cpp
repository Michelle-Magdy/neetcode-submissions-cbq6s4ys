class Solution {
public:
    bool ok(unordered_map<char,int>& targetCount,unordered_map<char,int>& checkCount){
        for(auto [key,value]:targetCount){
            if(value > checkCount[key]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ret = "";
        if(t.size()> s.size()) return ret;
        unordered_map<char,int> targetCount,currCount;
        for(int i=0;i<t.size();i++){
            targetCount[t[i]]++;
        }
        int l=0,start =0,len=0;
       
        for(int r=0;r<s.size();r++){
            currCount[s[r]]++;

            while(ok(targetCount,currCount)){
                start = l;
                len = r - l+1;
                currCount[s[l]]--;
                l++;
            }
            if(ret == ""||len < ret.size()){
                ret = s.substr(start,len);
            }
        }
        return ret;
    }
};
