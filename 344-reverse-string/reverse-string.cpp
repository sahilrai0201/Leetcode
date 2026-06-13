// APPROACH 1: TWO POINTER
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        // Initialize two pointers:
        // start -> beginning of the string
        // end   -> last character of the string
        int start = 0;
        int end = n - 1;

        // Keep swapping characters until the pointers meet
        while(start < end) {
            swap(s[start], s[end]);

            // Move start forward
            start++;

            // Move end backward
            end--;
        }
    }
};
*/


// APPROACH 2: STACK
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Stack follows LIFO (Last In, First Out)
        stack<char> st;

        // Push all characters into the stack
        for(char ch : s) {
            st.push(ch);
        }

        // Pop characters one by one and place them back
        // into the vector. Since stack returns elements
        // in reverse order, the string gets reversed.
        for(int i = 0; i < s.size(); i++) {
            s[i] = st.top();  // Get top character
            st.pop();         // Remove it from the stack
        }
    }
};