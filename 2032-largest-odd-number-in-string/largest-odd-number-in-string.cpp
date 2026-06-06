// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary space

class Solution {
public:
    string largestOddNumber(string num) {

        // Store the length of the string
        int n = num.length();

        // Traverse from right to left
        // We need the rightmost odd digit because
        // the largest odd-numbered prefix must end there
        for(int i = n - 1; i >= 0; i--){

            // Convert character digit to integer and check if it is odd
            // Example: '5' - '0' = 5, and 5 % 2 == 1
            if((num[i] - '0') % 2 == 1){

                // Return the prefix from index 0 to i (inclusive)
                // This forms the largest possible odd number
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found in the entire string,
        // so it is impossible to form an odd number
        return "";
    }
};