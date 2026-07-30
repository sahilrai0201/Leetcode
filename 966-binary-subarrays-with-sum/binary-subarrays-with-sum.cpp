// TC : O(n)
// SC : O(1)

class Solution {
public:
    // Returns the number of subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {

        // If goal becomes negative, no valid subarray exists
        if (goal < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Expand the window
            sum += nums[right];

            // Shrink the window until sum <= goal
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            // All subarrays ending at 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};




// Time Complexity: O(n)
// Space Complexity: O(n)

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int, int> mp;
//         mp[0] = 1;

//         int sum = 0;
//         int count  = 0;

//         for(int num : nums){
//             sum += num;

//             count += mp[sum - goal];

//             mp[sum]++;
//         }

//         return count;
//     }
// };