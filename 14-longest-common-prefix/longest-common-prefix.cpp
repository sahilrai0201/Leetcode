// APPROACH 3 : tries
// Time Complexity -> O(N × L)
// Space Complexity -> O(N × L)
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) { root = new TrieNode(ch); }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) { insertUtil(root, word); }

    void lcp(string str, string& ans) {
        TrieNode* temp = root;
        for (int i = 0; i < str.length(); i++) {
            //FIRST check terminal conditio
            if (temp->isTerminal) {
                break;
            }
            char ch = str[i];

            if (temp->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            } else {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie* t = new Trie('\0');

        for (int i = 0; i < n; i++) {
            t->insertWord(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first, ans);
        return ans;
    }
};

// APPROACH 2 :
// Time Complexity -> O(N × L)
// Space Complexity -> O(1) (or O(L) including output)
//  class Solution {
//  public:
//      string longestCommonPrefix(vector<string>& strs) {
//          if(strs.empty()) return "";
//          string ans = "";
//          int n = strs.size();

//         // traverse characters of first string
//         for(int i = 0; i < strs[0].length(); i++){
//             char ch = strs[0][i];

//             bool match = true;
//             // compare with rest of strings
//             for(int j = 1; j < n; j++){
//                 // check:
//                 // 1. index out of bound
//                 // 2. character mismatch
//                 if(i >= strs[j].length() || strs[j][i] != ch){
//                     match = false;
//                     break;
//                 }
//             }
//             if(match == false){
//                 break;
//             } else {
//                 ans.push_back(ch);
//             }
//         }
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