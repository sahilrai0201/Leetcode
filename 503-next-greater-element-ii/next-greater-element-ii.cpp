class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);   // Default answer = -1
        stack<int> st;            // Monotonic decreasing stack

        // Traverse twice from right to left
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Remove smaller or equal elements
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Fill answer only in the first pass (i < n)
            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }

            // Push current element
            st.push(nums[i % n]);
        }

        return ans;
    }
};