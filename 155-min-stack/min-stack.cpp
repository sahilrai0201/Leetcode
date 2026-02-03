class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val >= mini) {
            st.push(val);
        }
        else {
            // encode value
            st.push(2LL * val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long top = st.top();
        st.pop();

        if(top < mini) {
            // decode previous minimum
            mini = 2 * mini - top;
        }
    }
    
    int top() {
        long long top = st.top();
        if(top < mini)
            return mini;
        return top;
    }
    
    int getMin() {
        return mini;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */