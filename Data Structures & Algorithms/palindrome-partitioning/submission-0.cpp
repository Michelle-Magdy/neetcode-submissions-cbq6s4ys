class Solution {

private:
    bool checkPalindrom(const string& s , int l , int r){
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    void backtrack(int start, const string& s,
               vector<string>& current,
               vector<vector<string>>& result) {

        if (start == s.size()) {
            // push current into result
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            // we will add work here later
            if(checkPalindrom(s,start,end)){
                current.push_back(s.substr(start,end -start +1));
                backtrack(end+1,s,current,result);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<string> current;
               vector<vector<string>> result;
        backtrack(0,s,current,result);
        return result;
    }
};
