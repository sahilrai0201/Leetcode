class MinStack {
    stack<long long> st;
    long long mini;     // Stores current minimum element

public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            // First element becomes the minimum
            st.push(val);
            mini = val;
        }
        else if (val >= mini) {
            // Normal push if value is not a new minimum
            st.push(val);
        }
        else {
            // New minimum found
            // Store encoded value instead of actual value
            // Formula: encoded = 2 * newMin - oldMin
            st.push(2LL * val - mini);

            // Update current minimum
            mini = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        // Encoded value means the minimum element is being removed
        if (top < mini) {
            // Restore previous minimum
            // Formula: oldMin = 2 * currentMin - encoded
            mini = 2 * mini - top;
        }
    }
    
    int top() {
        long long top = st.top();

        // Encoded value represents the current minimum
        if (top < mini)
            return mini;

        // Otherwise return actual top value
        return top;
    }
    
    int getMin() {
        // Current minimum element
        return mini;
    }
};