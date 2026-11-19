// TC = O(nlogn)
// SC = O(1)

class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Case 1: Change two smallest elements
        int case1 = nums[n-1] - nums[2];

        // Case 2: Change smallest and largest elements
        int case2 = nums[n-2] - nums[1];

        // Case 3: Change two largest elements
        int case3 = nums[n-3] - nums[0];

        // Return the minimum among all three cases
        return min({case1, case2, case3});
    }
};