//TC = O(n*n) and SC = O(n) ->
class Solution {
public:
    // Find index of element in inorder traversal
    int findPosition(vector<int>& inorder, int element, int n){
        for(int i = 0; i < n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index,
                    int inorderStart, int inorderEnd, int n){       
        // base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        // create root from postorder
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        // find root position in inorder
        int position = findPosition(inorder, element, n);

        // IMPORTANT: build RIGHT subtree first
        root->right = solve(inorder, postorder, index, position+1, inorderEnd, n);

        // then LEFT subtree
        root->left = solve(inorder, postorder, index, inorderStart, position-1, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postOrderIndex = n-1;

        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n);

        return ans;
    }
};