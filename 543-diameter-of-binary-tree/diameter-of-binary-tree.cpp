//APPROACH 2 : TC - O(N)
class Solution {
public:
    pair<int, int> diameterFast(TreeNode* root){        
        //pair first part represents diameter & second represents height
        //base case
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;    //returns first part of ans which represents diameter 
    }
};





//APPROACH-1 : TC - O(N*N) : 
//HEIGHT IS CALLED INSIDE DIAMETER & IN WC BOTH FUNCTIONS ITERATES THE WHOLE TREE WHICH HAS N NODES
// class Solution {
// private:
//     int height(TreeNode* root){
//         //base case
//         if(root == NULL){
//             return 0;
//         }
//         int left = height(root->left);
//         int right = height(root->right);

//         return max(left, right) + 1;
//     }   
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         //base case
//         if(root == NULL){
//             return 0;
//         }
//         int op1 = diameterOfBinaryTree(root->left);  //diameter is in left subtree
//         int op2 = diameterOfBinaryTree(root->right);  //diameter is in right subtree
//         int op3 = height(root->left) + height(root->right);

//         int ans = max(op1, max(op2, op3));
//         return ans;
//     }
// };