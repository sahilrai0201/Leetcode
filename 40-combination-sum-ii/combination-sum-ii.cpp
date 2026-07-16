class Solution {
private:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& curr, vector<vector<int>>& ans) {

        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(index == candidates.size())
            return;

        if(candidates[index] <= target){
            curr.push_back(candidates[index]);

            // Pick current element (use once)
            solve(index + 1, candidates,
                  target - candidates[index], curr, ans);

            curr.pop_back();
        }

        // Skip all duplicates
        int next = index + 1;
        while(next < candidates.size() &&
              candidates[next] == candidates[index]){
            next++;
        }

        // Not Pick
        solve(next, candidates, target, curr, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);

        return ans;
    }
};