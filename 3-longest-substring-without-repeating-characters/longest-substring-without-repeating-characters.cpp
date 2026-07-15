class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> lastIndex;

        int i = 0;
        int maxLen = 0;
        int start = 0;

        for(int j=0; j<n; j++){
            if(lastIndex.count(s[j]) && lastIndex[s[j]] >= i){
                i = lastIndex[s[j]] + 1;
            }

            lastIndex[s[j]] = j;

            if(j - i + 1 > maxLen){
                maxLen = j - i + 1;
                start = i;
            }
        }

        return maxLen;
    }
};