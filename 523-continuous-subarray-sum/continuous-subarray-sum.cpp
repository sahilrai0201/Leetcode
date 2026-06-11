//TC = O(N) & SC = O(MIN(N, K)) -------------------------------->

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // Stores: remainder -> first index where it appeared
        unordered_map<int, int> mp;

        // Remainder 0 is considered to occur before the array starts
        mp[0] = -1;

        int prefix = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Compute running prefix sum
            prefix += nums[i];

            // Current remainder
            int rem = prefix % k;

            // Same remainder seen before
            if(mp.count(rem)) {

                // Subarray length must be at least 2
                if(i - mp[rem] >= 2) {
                    return true;
                }
            }
            else {
                // Store first occurrence only
                mp[rem] = i;
            }
        }

        return false;
    }
};