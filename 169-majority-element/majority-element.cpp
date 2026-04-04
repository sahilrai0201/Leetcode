//APPROACH 2 : 
//TC = O(n log n) and SC = O(n) : 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto j : mp){
            if(j.second > n/2){
                return j.first;
            }
        }
        return -1;    //just in-case
    }
};


//APPROACH 1: 
// TC = O(n) and SC = O(1) :
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int candidate = nums[0], vote = 1;
//         for(int i=1; i<nums.size(); i++){
//             if(vote == 0) {
//                 candidate = nums[i];
//                 vote = 1;
//             }
//             else if(nums[i] == candidate) {
//                 vote++;
//             }
//             else{
//                 vote--;
//             }
//         }
//         return candidate;
//     }
// };