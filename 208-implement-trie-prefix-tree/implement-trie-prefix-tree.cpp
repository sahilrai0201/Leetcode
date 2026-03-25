// Node of Trie
class TrieNode{
    public:
    char data;                  // stores character
    TrieNode* children[26];     // array of pointers for 26 letters (a-z)
    bool isTerminal;            // marks end of a word

    // constructor
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL; // initially no children
        }
        isTerminal = false;     // initially not end of word
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0'); // root node (empty character)
    }

    // recursive function to insert word
    void insertUtil(TrieNode* root, string word){
        // base case: if word is empty → mark terminal
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // get index (0–25) for current character
        int index = word[0] - 'a';
        TrieNode* child;

        // if character already exists → move to that node
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // if not present → create new node
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call for remaining word
        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        for(char &c : word) c = tolower(c); // convert to lowercase
        insertUtil(root, word);
    }

    // recursive function to search word
    bool searchUtil(TrieNode* root, string word){
        // base case: if word ends → check terminal
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // if character exists → move forward
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // character not found → word not present
            return false;
        }

        // recursive search for remaining word
        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        for(char &c : word) c = tolower(c); // convert to lowercase
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode* root, string word){
        // base case: if word ends → check terminal
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // if character exists → move forward
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // character not found → word not present
            return false;
        }

        // recursive search for remaining word
        return prefixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */