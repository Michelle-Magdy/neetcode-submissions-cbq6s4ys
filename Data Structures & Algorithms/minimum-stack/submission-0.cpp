class MinStack {
private:
    stack<long> st;
    long min_val;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min_val = val;
        }else{
            st.push(val - min_val);
            if(val < min_val) min_val = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long pop  = st.top();
        st.pop();
        if(pop < 0) min_val = min_val - pop;
    }
    
    int top() {
        long top = st.top();
        return (top > 0)? (top + min_val): (int) min_val; 
    }
    
    int getMin() {
        return min_val;
    }
};
