class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;

        // Convert linked list to array
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;   // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        // Remaining indices have no greater element
        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};