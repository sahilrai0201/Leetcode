//APPROACH-1 : TC = O(N) & SC = O(N)-------------------------------->
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        int missing, duplicate;

        //count freq of each number
        for(int num : nums){
            count[num]++;
        }

        //find duplicate and missing numbers
        for(int i=1; i<=n; i++){
            if(count[i] == 2){
                duplicate = i;
            }
            else if(count[i] == 0){
                missing = i;
            }
        }
        return {duplicate, missing};
    }
};



//APPROACH-2 : TC = O(N) & SC = o(1)---------------------------->
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();
        
//         int dup = -1;
//         int missing = -1;

//         for(int i=0; i<n; i++){
//             if(nums[abs(nums[i]) - 1] < 0){
//                 dup = abs(nums[i]);
//             } else {
//                 nums[abs(nums[i]) - 1] = (-1) * nums[abs(nums[i]) - 1];
//             }
//         }

//         for(int i=0; i<n; i++){
//             if(nums[i] > 0){
//                 missing = (i+1);
//                 break;
//             }
//         }
//         return {dup, missing};
//     }
// };