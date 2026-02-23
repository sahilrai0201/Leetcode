class Solution {
public:
    int longestPalindrome(string s) {
        // Create a frequency array of size 128 (ASCII characters)
        // Initialize all values to 0
        vector<int> freq(128, 0);

        for(char c : s){         // Count frequency of each character in the string
            freq[c]++;      // Increase frequency using ASCII value as index
        }

        int length = 0;      // Stores maximum palindrome length
        bool hasOdd = false; // To check if any character has odd frequency

        // Traverse through all character frequencies
        for(int count : freq){
            
            // If frequency is even, we can use all characters in palindrome
            if(count % 2 == 0){
                length += count;
            }
            else{
                // If frequency is odd, we can use (count - 1) characters because palindrome needs pairs
                length += count - 1;
                hasOdd = true;    // Mark that we found at least one odd frequency
            }
        }
        // If at least one odd frequency exists,
        // we can place exactly ONE character in the center
        if(hasOdd) length += 1;

        // Return maximum possible palindrome length
        return length;
    }
};