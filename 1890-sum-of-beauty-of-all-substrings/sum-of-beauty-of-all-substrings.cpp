// Time Complexity: O(n²)
// Space Complexity: O(1) 

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();

        // Stores the final sum of beauty values of all substrings
        int ans = 0;

        // Fix the starting index of the substring
        for(int i = 0; i < n; i++) {

            // Frequency array for characters in the current substring
            vector<int> freq(26, 0);

            // Extend the substring from index i to j
            for(int j = i; j < n; j++) {

                // Include the current character in the substring
                freq[s[j] - 'a']++;

                // Variables to store maximum and minimum
                // character frequencies in the current substring
                int maxFreq = 0;
                int minFreq = INT_MAX;

                // Traverse all 26 lowercase letters
                // to find max and min non-zero frequencies
                for(int k = 0; k < 26; k++) {

                    // Consider only characters that are present
                    // in the current substring
                    if(freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // Beauty of current substring =
                // (maximum frequency - minimum frequency)
                ans += (maxFreq - minFreq);
            }
        }

        // Return the sum of beauty values
        // of all possible substrings
        return ans;
    }
};