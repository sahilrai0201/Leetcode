class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans, int level){
        //base case
        if(root == NULL) return;

        //we entererd new level
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        //moving from right to left
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);        //root, ans, level
        return ans;
    }
};