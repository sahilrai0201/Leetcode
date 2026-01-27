//APPROACH_1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};


//APPROACH_2
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int maxi = nums[0];

//         for(int i=0; i<nums.size(); i++){
//             sum = sum + nums[i];
//             maxi = max(maxi, sum);

//             if(sum < 0){
//                 sum = 0;
//             }
//         }
//         return maxi;
//     }
// };