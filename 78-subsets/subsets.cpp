class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                // Check if ith bit is set
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};




// -------------------------------------------------------->
// class Solution {
// private:
//     void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
//         // Base case: one subset is formed
//         if(index >= nums.size()){
//             ans.push_back(output);
//             return;
//         }

//         // Exclude current element
//         solve(nums, output, index + 1, ans);

//         // Include current element
//         output.push_back(nums[index]);
//         solve(nums, output, index + 1, ans);
//     }

// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> output;

//         // Start recursion from index 0
//         solve(nums, output, 0, ans);

//         return ans;
//     }
// };

// /*
// Time Complexity: O(N * 2^N)
// Space Complexity:
// - Auxiliary (recursion + output): O(N)
// - Including answer storage: O(N * 2^N)
// */