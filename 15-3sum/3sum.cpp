//OPTIMISED SOLUTION---------------------------------------------------->
//TC : O(N*N) & SC : O(1)----------------------------------------------->
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n; i++){
            int a = nums[i];           //a+b+c=0 then b+c=-a
            int t = -a;
            int s = i+1, e = n-1;
            while(s<e){
                if(nums[s] + nums[e] == t){
                    ans.push_back({nums[i], nums[s], nums[e]});
                    while(s<e && nums[s] == nums[s+1]) s++;
                    while(s<e && nums[e] == nums[e-1]) e--;
                    s++;
                    e--;
                }
                else if(nums[s] + nums[e] > t){
                    e--;
                }
                else{
                    s++;
                }
            }
            while(i+1<n && nums[i+1] == nums[i]){
                i++;
            }
        }
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