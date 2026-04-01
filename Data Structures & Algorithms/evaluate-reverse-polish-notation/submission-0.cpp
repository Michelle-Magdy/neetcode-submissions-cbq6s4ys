class Solution {
public:
    int op(int x,int y,string opt){
        if(opt == "+") return x+ y;
        else if(opt =="-") return x-y;
        else if(opt =="/") return x/y;
        return x *y;
    }
    int evalRPN(vector<string>& tokens) {
        set<string> s = { "+","-","/","*"};
        stack<int> st;

        for(string t: tokens){
            if(s.count(t)){
                int y = st.top();;
                st.pop();
                int x = st.top();
                st.pop();
                st.push(op(x,y,t));
            }else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
