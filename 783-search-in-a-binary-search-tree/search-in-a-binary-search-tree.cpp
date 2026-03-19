// Time Complexity (Both Approaches)
// Best Case: O(1) → value found at root
// Average Case: O(log n) → balanced BST
// Worst Case: O(n) → skewed BST


//APPROACH 2 : ITERATIVE ->
// Space: O(1)
// 👉 No extra memory used, just a pointer

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while(temp != NULL){
            if(temp->val == val){
                return temp;
            }
            if(val > temp->val){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        return NULL;
    }
};



//APPROACH 1 : RECURSIVE ->
// Space: O(h)
// Balanced BST → O(log n)
// Skewed BST → O(n)
// 👉 Due to recursion stack

// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         //base case
//         if(root == NULL || root->val == val){
//             return root;
//         }

//         //recursive calls
//         if(val < root->val){
//             return searchBST(root->left, val);
//         }
//         else{
//             return searchBST(root->right, val);
//         }
//     }
// };