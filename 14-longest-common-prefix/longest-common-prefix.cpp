// APPROACH 2 : Vertical Scanning
// Time Complexity -> O(N × L)
// N = number of strings
// L = length of the shortest common prefix
// Space Complexity -> O(1) (or O(L) including output)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // If the vector is empty, no common prefix exists
        if(strs.empty()) return "";
        
        // Stores the final longest common prefix
        string ans = "";
        
        // Total number of strings
        int n = strs.size();

        // Traverse each character of the first string
        for(int i = 0; i < strs[0].length(); i++){
            
            // Current character to be matched in all strings
            char ch = strs[0][i];

            // Assume character matches initially
            bool match = true;
            
            // Compare the current character with all remaining strings
            for(int j = 1; j < n; j++){
                
                // Check:
                // 1. Current index exceeds length of a string
                // 2. Character at current index does not match
                if(i >= strs[j].length() || strs[j][i] != ch){
                    match = false;
                    break;
                }
            }
            
            // If mismatch found, common prefix ends here
            if(match == false){
                break;
            } 
            else {
                // Character matched in all strings,
                // add it to the answer
                ans.push_back(ch);
            }
        }
        
        // Return the longest common prefix
        return ans;
    }
};










// APPROACH 3 : tries
// Time Complexity -> O(N × L)
// Space Complexity -> O(N × L)
// class TrieNode {
// public:
//     char data;
//     TrieNode* children[26];
//     int childCount;
//     bool isTerminal;

//     TrieNode(char ch) {
//         data = ch;
//         for (int i = 0; i < 26; i++) {
//             children[i] = NULL;
//         }
//         childCount = 0;
//         isTerminal = false;
//     }
// };

// class Trie {
// public:
//     TrieNode* root;

//     Trie(char ch) { root = new TrieNode(ch); }

//     void insertUtil(TrieNode* root, string word) {
//         if (word.length() == 0) {
//             root->isTerminal = true;
//             return;
//         }

//         int index = word[0] - 'a';
//         TrieNode* child;

//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             child = new TrieNode(word[0]);
//             root->childCount++;
//             root->children[index] = child;
//         }

//         insertUtil(child, word.substr(1));
//     }

//     void insertWord(string word) { insertUtil(root, word); }

//     void lcp(string str, string& ans) {
//         TrieNode* temp = root;
//         for (int i = 0; i < str.length(); i++) {
//             //FIRST check terminal conditio
//             if (temp->isTerminal) {
//                 break;
//             }
//             char ch = str[i];

//             if (temp->childCount == 1) {
//                 ans.push_back(ch);
//                 int index = ch - 'a';
//                 temp = temp->children[index];
//             } else {
//                 break;
//             }
//         }
//     }
// };

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs.size();
//         Trie* t = new Trie('\0');

//         for (int i = 0; i < n; i++) {
//             t->insertWord(strs[i]);
//         }

//         string first = strs[0];
//         string ans = "";

//         t->lcp(first, ans);
//         return ans;
//     }
// };








// APPROACH 1 :
// Time Complexity -> O(NlogN × L)
// Space Complexity -> O(1)
//  class Solution {
//  public:
//      string longestCommonPrefix(vector<string>& strs) {
//          if(strs.empty()) return "";
//          sort(strs.begin(), strs.end());

//         string first = strs[0];
//         string last = strs.back();

//         string result = "";

//         int i = 0;
//         while(i < first.size() && i < last.size()){
//             if(first[i] == last[i]){
//                 result = result + first[i];
//                 i++;
//             }
//             else{
//                 break;
//             }
//         }
//         return result;
//     }
// };