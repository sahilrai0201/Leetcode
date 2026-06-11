//TC = O(N) & SC = O(1)-------------------------->

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        // Tracks the current depth of nested parentheses
        int count = 0;

        // Stores the maximum depth encountered so far
        int maxCount = count;

        // Traverse the entire string
        for(int i=0; i<n; i++){

            // Opening parenthesis increases the current depth
            if(s[i] == '('){
                count++;
            }

            // Closing parenthesis decreases the current depth
            else if(s[i] == ')'){
                count--;
            }

            // Update maximum depth after processing current character
            maxCount = max(count, maxCount);
        }

        // Return the maximum nesting depth
        return maxCount;
    }
};