class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int count  = 0;

        for(int num : nums){
            sum += num;

            count += mp[sum - goal];

            mp[sum]++;
        }

        return count;
    }
};