// TC : O(n)
// SC : O(1)

class Solution {
private:
    // Returns the number of subarrays having at most k odd numbers
    int atMost(vector<int> &nums, int k) {

        // No valid subarray can have at most negative odd numbers
        if (k < 0) return 0;

        int left = 0;     // Left boundary of the sliding window
        int odd = 0;      // Number of odd elements in the current window
        int count = 0;    // Total valid subarrays

        for (int right = 0; right < nums.size(); right++) {

            // Include the current element in the window
            if (nums[right] % 2 != 0) {
                odd++;
            }

            // Shrink the window until it has at most k odd numbers
            while (odd > k) {
                if (nums[left] % 2 != 0) {
                    odd--;
                }
                left++;
            }

            // All subarrays ending at 'right' and starting
            // from 'left' to 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // Exactly k odd numbers =
        // (Subarrays with at most k odd numbers)
        // - (Subarrays with at most (k - 1) odd numbers)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};