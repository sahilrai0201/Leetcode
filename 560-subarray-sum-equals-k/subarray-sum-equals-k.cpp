class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;  // stores prefix sum frequencies
        prefixSumCount[0] = 1;  // base case: one way to have sum = 0 before starting
        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;

            // check if there is a prefix sum that makes currentSum - prefixSum = k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // record the current prefix sum
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};