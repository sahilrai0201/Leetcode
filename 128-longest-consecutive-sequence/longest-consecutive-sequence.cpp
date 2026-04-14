class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 1;
        int maxCount = 1;

        int i = 0;
        while(i < n-1){
            if(nums[i] == nums[i+1]){
                i++;
                continue;
            }
            else if(nums[i] + 1 == nums[i+1]){
                count++;
            }
            else{
                maxCount = max(maxCount, count);
                count = 1;
            }
            i++;
        }
        return max(maxCount, count);
    }
};