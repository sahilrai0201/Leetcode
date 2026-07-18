class Solution {
private:
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        // Store current subset
        ans.push_back(output);

        // Try every possible element
        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Include current element
            output.push_back(nums[i]);

            // Recur for remaining elements
            solve(nums, output, i + 1, ans);

            // Backtrack
            output.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        // Sort to bring duplicates together
        sort(nums.begin(), nums.end());

        // Start recursion
        solve(nums, output, 0, ans);

        return ans;
    }
};

/*
Time Complexity:
O(n * 2^n)

Space Complexity:
Auxiliary: O(n)          // recursion + output
Including answer: O(n * 2^n)
*/