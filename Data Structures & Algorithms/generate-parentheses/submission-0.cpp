class Solution {
public:
    void backtrack(int openN ,int closedN,int n ,vector<string>& res,string& st){
        if(openN == closedN && openN  == n) {
            res.push_back(st);
            return;
        }
        if(openN < n) {
            st += '(';
            backtrack(openN+1,closedN,n,res,st);
            st.pop_back();
            
        }
        if(closedN  < openN){
            st += ')';
            backtrack(openN,closedN + 1,n,res,st);
            st.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st;
        backtrack(0,0,n,res,st);
        return res;
    }
};
