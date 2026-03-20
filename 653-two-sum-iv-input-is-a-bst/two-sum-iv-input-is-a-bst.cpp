class Solution {
public:
    // Function to perform inorder traversal and store values in sorted order
    void inorder(TreeNode* root, vector<int> &inorderVal){
        
        // Base case: if node is NULL, do nothing
        if(root == NULL) return;

        // Step 1: Traverse left subtree (smaller elements)
        inorder(root->left, inorderVal);

        // Step 2: Visit current node (store value)
        inorderVal.push_back(root->val);

        // Step 3: Traverse right subtree (larger elements)
        inorder(root->right, inorderVal);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;

        // Get sorted values of BST using inorder traversal
        inorder(root, inorderVal);

        // Two-pointer approach on sorted array
        int i = 0;                          // start pointer
        int j = inorderVal.size() - 1;      // end pointer

        while(i < j){
            int sum = inorderVal[i] + inorderVal[j];

            // If pair found
            if(sum == k) return true;

            // If sum is too large, move right pointer left
            else if(sum > k) j--;

            // If sum is too small, move left pointer right
            else i++;
        }

        // No valid pair found
        return false;
    }
};