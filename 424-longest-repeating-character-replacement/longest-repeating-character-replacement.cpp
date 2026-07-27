class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> freq(26, 0);   // Frequency of characters A-Z

        int i = 0;                 // Left pointer
        int maxFreq = 0;           // Highest frequency in current window
        int maxLen = 0;            // Answer

        // Expand the window
        for (int j = 0; j < n; j++) {

            // Increase frequency of current character
            freq[s[j] - 'A']++;

            // Update the maximum frequency in the window
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            // If replacements needed exceed k,
            // shrink the window
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            // Update answer
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};