class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({temperatures[i],i});
            }else{
                pair<int,int> top = st.top();
                if(temperatures[i] <= top.first){
                    st.push({temperatures[i],i});
                }else{
                    while(temperatures[i] > top.first){
                        res[top.second] = i - top.second;
                        st.pop();
                        if(st.empty()) break;
                        top = st.top();
                    }
                    st.push({temperatures[i],i});
                }
            }
        }
        return res;
    }
};
