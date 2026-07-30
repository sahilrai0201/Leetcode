// TC = O(N)
// SC = O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Stores: {prefixSum -> frequency}
        unordered_map<int, int> mp;

        // Base case:
        // A prefix sum of 0 occurs once before starting the array.
        mp[0] = 1;

        int sum = 0;    // Running prefix sum
        int count = 0;  // Total number of valid subarrays

        // Traverse the array
        for (int num : nums) {

            // Update the current prefix sum
            sum += num;

            // If (current prefix sum - k) exists,
            // then there are subarray(s) ending at the current index
            // whose sum equals k.
            count += mp[sum - k];

            // Store/update the frequency of the current prefix sum
            mp[sum]++;
        }

        // Return the total number of subarrays with sum = k
        return count;
    }
};