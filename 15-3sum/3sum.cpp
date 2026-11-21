//OPTIMISED SOLUTION---------------------------------------------------->
// Time Complexity: O(N^2)
// Space Complexity: O(1) auxiliary space (excluding sorting's internal stack
// and output storage). Including sorting's stack: O(log N).


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array to apply the two-pointer approach
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Step 2: Fix the first element of the triplet
        for(int i=0; i<n; i++){

            int a = nums[i];           // a + b + c = 0
            int t = -a;                // Therefore, b + c = -a

            // Step 3: Initialize two pointers to find the remaining two elements
            int s = i+1, e = n-1;

            // Step 4: Search for a pair whose sum equals the target
            while(s<e){

                // CASE 1: Pair sum is equal to the target
                if(nums[s] + nums[e] == t){

                    // Store the valid triplet in the answer
                    ans.push_back({nums[i], nums[s], nums[e]});

                    // Skip duplicate elements from the left side
                    while(s<e && nums[s] == nums[s+1]){
                        s++;
                    }

                    // Skip duplicate elements from the right side
                    while(s<e && nums[e] == nums[e-1]){
                        e--;
                    }

                    // Move both pointers to search for another unique pair
                    s++;
                    e--;
                }

                // CASE 2: Pair sum is greater than the target
                else if(nums[s] + nums[e] > t){

                    // Decrease the sum by moving the right pointer left
                    e--;
                }

                // CASE 3: Pair sum is smaller than the target
                else{

                    // Increase the sum by moving the left pointer right
                    s++;
                }
            }

            // Step 5: Skip duplicate values of the fixed element
            // This prevents generating duplicate triplets
            while(i+1<n && nums[i+1] == nums[i]){
                i++;
            }
        }

        // Step 6: Return all unique triplets whose sum is zero
        return ans;
    }
};




//BRUTE FORCE------------------------------------------------------------->
//TC : O(n³ log n) & SC : O(n²)------------------------------------------->
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> st;

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 for(int k=j+1; k<n; k++){
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> temp = {nums[i], nums[j], nums[k]};
//                         sort(temp.begin(), temp.end());

//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };