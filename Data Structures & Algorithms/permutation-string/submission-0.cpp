class Solution {
public:
    bool ok(unordered_map<char,int>& count1 ,unordered_map<char,int>& count2){
        for(auto [key,value]: count1){
            if(value != count2[key]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> count1,count2;
        int ws = s1.size();
        for(int i =0;i<ws;i++){
            count1[s1[i]]++;
            count2[s2[i]]++;
        }
        bool ret = ok(count1,count2);
        if(ret) return ret;
    
        for(int r = ws;r<s2.size();r++){
            count2[s2[r - ws]]--;
            count2[s2[r]]++;
            ret = ok(count1,count2);
            if(ret) return true;
        }
        return ret;
    }
};
