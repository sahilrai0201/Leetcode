class Solution {
public:
    int solve(TreeNode* root, int &k){
        //base case
        if(root == NULL) return -1;

        //left
        int left = solve(root->left, k);
        if(left != -1) return left;

        //node
        k--;
        if(k == 0) return root->val;

        //right
        return solve(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
    }
};