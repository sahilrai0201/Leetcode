//APPROACH-2 : 
class Solution {
private:
    int height(TreeNode* root){
        //base case
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left, right) + 1;
        return ans;
    }    
public:
    bool isBalanced(TreeNode* root) {
        //base case
        if (root == NULL) return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if(left && right && diff){
            return true;
        } 
        else{
            return false;
        }
    }
};






//APPROACH-1 : 
// class Solution {
// public:
//     int height(TreeNode* root) {
//         if (root == NULL) return 0;

//         int left = height(root->left);
//         if (left == -1) return -1;

//         int right = height(root->right);
//         if (right == -1) return -1;

//         if (abs(left - right) > 1) return -1;

//         return 1 + max(left, right);
//     }

//     bool isBalanced(TreeNode* root) {
//         if(height(root) != -1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };