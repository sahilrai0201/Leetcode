class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {
            bool destroyed = false;   // Is current asteroid destroyed?

            // Collision possible only: +ve (stack) vs -ve (current)
            while (!st.empty() && st.top() > 0 && x < 0) {

                if (st.top() < -x) {
                    st.pop();          // Stack asteroid explodes
                }
                else if (st.top() == -x) {
                    st.pop();          // Both explode
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;  // Current asteroid explodes
                    break;
                }
            }

            // Push only if current asteroid survives
            if (!destroyed) {
                st.push(x);
            }
        }

        // Convert stack to answer vector
        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};