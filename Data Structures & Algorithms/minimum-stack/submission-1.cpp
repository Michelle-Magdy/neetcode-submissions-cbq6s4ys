class MinStack {
private:
    stack<long> st;
    long min_val;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       if(st.empty()){
        min_val = val;
        st.push(0);
       }else{
        st.push(val - min_val);
        if(st.top() < 0) min_val = val;
       }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() > 0) st.pop();
        else {
            min_val = min_val - st.top();
            st.pop();
        }
        
    }
    
    int top() {
      return (st.top() > 0 )? st.top() + min_val : min_val;
    }
    
    int getMin() {
        return min_val;
    }
};
