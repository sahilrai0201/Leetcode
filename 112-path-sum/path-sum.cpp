class Solution {
public:
    bool solve(TreeNode* root, int k, vector<int> &path){
        if(root == NULL) return false;

        path.push_back(root->val);

        //check only at leaf node
        if(root->left == NULL && root->right == NULL){
            int sum = 0;
            for(int i=0; i<path.size(); i++){
                sum += path[i];
            }
            if(sum == k){
                path.pop_back();
                return true;
            }
        }

        if(solve(root->left, k, path)){
            path.pop_back();
            return true;
        }

        if(solve(root->right, k, path)){
            path.pop_back();
            return true;
        }

        path.pop_back();
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        return solve(root, targetSum, path);
    }
};