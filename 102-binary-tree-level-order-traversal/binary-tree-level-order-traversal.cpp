class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left) q.push(temp->left);       //left is non-null
                if(temp->right) q.push(temp->right);      //right is non null
            }
            ans.push_back(level);
        }
        return ans;
    }
};