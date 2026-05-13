class Solution {
public:
    unordered_map<char,string> phone;
    void backtrack(int i ,string& digits,string& s,vector<string>& res){
        if(i == digits.size()){
            res.push_back(s);
            return;
        }

        string chars = phone[digits[i]];
        for(int j = 0; j<chars.size();j++){
            s+=chars[j];
            backtrack(i+1,digits,s,res);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        phone['2'] ="abc";
        phone['3'] ="def";
        phone['4'] ="ghi";
        phone['5'] ="jkl";
        phone['6'] ="mno";
        phone['7'] ="pqrs";
        phone['8'] ="tuv";
        phone['9'] ="wxyz";

        string s="";
        vector<string> res;
        backtrack(0,digits,s,res);
        return res;

    }
};