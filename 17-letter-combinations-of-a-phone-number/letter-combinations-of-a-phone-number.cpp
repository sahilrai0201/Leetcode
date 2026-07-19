class Solution {
private:
    void solve(int index, string digits, string mapping[], string output,
               vector<string>& ans) {

        // Base Case: processed all digits
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        // Get letters corresponding to current digit
        int number = digits[index] - '0';
        string value = mapping[number];

        // Try every possible letter
        for (int i = 0; i < value.length(); i++) {

            // PICK
            output.push_back(value[i]);

            // Recur for next digit
            solve(index + 1, digits, mapping, output, ans);

            // BACKTRACK
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;

        // Edge case
        if (digits.length() == 0)
            return ans;
    
        string output;

        // Digit -> Letters mapping
        string mapping[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        // Start recursion
        solve(0, digits, mapping, output, ans);

        return ans;
    }
};