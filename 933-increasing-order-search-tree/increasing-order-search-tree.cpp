class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inorderVal){
        if(root == NULL) return;

        //inorder -> LNR
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }

    TreeNode* increasingBST(TreeNode* root) {
        //step 1
        vector<int> inorderVal;
        inorder(root, inorderVal);
        int n = inorderVal.size();

        //step 2
        TreeNode* newRoot = new TreeNode(inorderVal[0]);
        TreeNode* curr = newRoot;

        for(int i=1; i<n; i++){
            TreeNode* temp = new TreeNode(inorderVal[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        //step 3
        curr->left = NULL;
        curr->right = NULL;

        return newRoot;
    }
};