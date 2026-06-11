// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string s) {

        // Mapping of Roman numerals to their integer values
        unordered_map<char, int> values = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        // Stores the final integer value
        int total = 0;

        // Length of the Roman numeral string
        int n = s.size();

        // Traverse each character in the string
        for(int i = 0; i < n; i++){

            // If the current Roman numeral has a smaller value than
            // the next numeral, it should be subtracted
            // Example: IV = 5 - 1 = 4, IX = 10 - 1 = 9
            if(i + 1 < n && values[s[i]] < values[s[i+1]]){
                total = total - values[s[i]];
            }

            // Otherwise, add the current numeral's value
            else{
                total = total + values[s[i]];
            }
        }

        // Return the converted integer value
        return total;
    }
};