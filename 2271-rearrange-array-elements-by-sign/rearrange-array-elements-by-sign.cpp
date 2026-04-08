//APPROACH 2 : TC = O() & SC = O()------------------------>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0, neg = 1;

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos = pos + 2;
            } 
            else{
                ans[neg] = nums[i];
                neg = neg + 2;
            }
        }
        return ans;
    }
};




//APPROACH 1 : TC = O(N) & SC = O(N)--------------->
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pos;
//         vector<int> neg;
//         // Step 1: Separate positives and negatives
//         for(int i = 0; i < n; i++){
//             if(nums[i] < 0){
//                 neg.push_back(nums[i]);
//             }
//             else{
//                 pos.push_back(nums[i]);
//             }
//         }
//         // Step 2: Merge alternately
//         vector<int> result;
//         int i = 0, j = 0;

//         while(i < pos.size() && j < neg.size()){
//             result.push_back(pos[i++]);
//             result.push_back(neg[j++]);
//         }
//         return result;
//     }
// };
