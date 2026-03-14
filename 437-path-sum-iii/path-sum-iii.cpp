class Solution {
public:
    int countPath(TreeNode* root, long long sum){
        if(root == NULL) return 0;

        int count = 0;
        if(root->val == sum) count++;

        count += countPath(root->left, sum - root->val);
        count += countPath(root->right, sum - root->val);

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int ans = 0;

        ans += countPath(root, targetSum);
        
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);

        return ans;
    }
};