//ITERATIVE APPROACH -> Space Optimisation
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
};




//RECURSIVE APPROACH ->
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //base case
//         if(root == NULL) return NULL;

//         if(root->val < p->val && root->val < q->val){
//             return lowestCommonAncestor(root->right, p, q);
//         }

//         if(root->val > p->val && root->val > q->val){
//             return lowestCommonAncestor(root->left, p, q);
//         }

//         return root;
//     }
// };