class Solution {
private:
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++; end--;
        }
        return true;
    }

    void solve(string &s, int start, vector<string> &curr, vector<vector<string>> &ans){
        if(start == s.length()){
            ans.push_back(curr);
            return;
        }

        for(int end = start; end < s.length(); end++){
            if(isPalindrome(s, start, end)){
                // PICK
                curr.push_back(s.substr(start, end - start + 1));
                solve(s, end + 1, curr, ans);
                curr.pop_back();
            }
        }
    }   

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        solve(s, 0, curr, ans);

        return ans;
    }
};