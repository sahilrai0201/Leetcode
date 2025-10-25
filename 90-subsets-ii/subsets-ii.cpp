class Solution {
private:
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        ans.push_back(output);  // every subset is valid

        for (int i = index; i < nums.size(); i++) {
            // skip duplicates at the same recursion depth
            if (i > index && nums[i] == nums[i - 1]) continue;

            output.push_back(nums[i]);
            solve(nums, output, i + 1, ans);
            output.pop_back();  // backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end()); // sort to group duplicates
        solve(nums, output, 0, ans);
        return ans;
    }
};
