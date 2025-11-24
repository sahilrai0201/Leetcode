class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        vector<bool> ans;
        int digit = 0;

        for(int i=0; i<nums.size(); i++){
            digit = (digit * 2 + nums[i]) % 5;

            ans.push_back(digit == 0);
        }
        return ans;
    }
};