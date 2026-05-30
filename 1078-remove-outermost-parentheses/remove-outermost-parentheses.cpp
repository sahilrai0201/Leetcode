class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;      // Stores the final answer
        int depth = 0;   // Tracks current nesting level

        for(char ch : s){

            // Opening parenthesis
            if(ch == '('){

                // If depth > 0, this '(' is not the outermost one,
                // so we keep it in the answer.
                if(depth > 0){
                    ans += ch;
                }

                // Increase nesting level
                depth++;
            }

            // Closing parenthesis
            else{

                // Decrease nesting level first because we are leaving
                // one level of nesting.
                depth--;

                // If depth is still > 0 after decrementing,
                // this ')' is not the outermost one,
                // so we keep it in the answer.
                if(depth > 0){
                    ans += ch;
                }
            }
        }

        return ans;
    }
};

//TC = O(N) & SC = O(N) --------------------------------------------------->