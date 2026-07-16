class Solution {
private:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& curr, vector<vector<int>>& ans) {

        // Base Case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // Out of bounds
        if (index == candidates.size()) {
            return;
        }

        // PICK (stay at same index because we can reuse the element)
        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);

            solve(index, candidates, target - candidates[index], curr, ans);

            curr.pop_back();    // Backtrack
        }

        // NOT PICK (move to next index)
        solve(index + 1, candidates, target, curr, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);

        return ans;
    }
};