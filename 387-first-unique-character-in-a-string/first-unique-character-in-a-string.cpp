class Solution {
public:
    int firstUniqChar(string s) {
        // For each character, check if it repeats
        for (int i = 0; i < s.size(); i++) {
            bool isUnique = true;

            // Compare s[i] with all other characters
            for (int j = 0; j < s.size(); j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break; // no need to check further
                }
            }

            // If no duplicate found, return index
            if (isUnique) {
                return i;
            }
        }

        // If no unique character exists
        return -1;
    }
};