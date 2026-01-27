class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            // Check if character is uppercase
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a'; // convert to lowercase
            }
        }
        return s; // return the updated string
    }
};



/* 
class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);  // convert each char directly
        }
        return s;
    }
};  
*/