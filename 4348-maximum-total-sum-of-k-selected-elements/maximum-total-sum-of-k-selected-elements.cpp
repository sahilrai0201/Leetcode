class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        long long sum = 0;

        for(int i=0; i < min(k, n); i++){
            if(mul >= 1){
                sum = sum + (long long) nums[i] * mul;
                mul--;
            }
            else{
                sum = sum + nums[i];
            }
        }

        return sum;
    }
};