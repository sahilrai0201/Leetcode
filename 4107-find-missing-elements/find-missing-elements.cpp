class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for(int i = mini; i <= maxi; i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};





// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         int n = nums.size();

//         sort(nums.begin(), nums.end());

//         vector<int> ans;

//         for(int i = 0; i < n - 1; i++){
//             int curr = nums[i];
//             int next = nums[i + 1];

//             for(int x = curr + 1; x < next; i++){
//                 ans.push_back(x);
//             }
//         }

//         return ans;
//     }
// };