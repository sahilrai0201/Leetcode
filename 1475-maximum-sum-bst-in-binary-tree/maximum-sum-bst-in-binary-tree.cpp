class Solution {
public:

    class info{
      public:
        int maxi;
        int mini;
        bool isBST;
        int sum;  
    };

    info solve(TreeNode* root, int &ans){
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info currNode;

        currNode.sum = left.sum + right.sum + root->val;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);

        if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini){
            currNode.isBST = true;
            ans = max(ans, currNode.sum);
        }
        else{
            currNode.isBST = false;
            currNode.maxi = INT_MAX;
            currNode.mini = INT_MIN;
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};