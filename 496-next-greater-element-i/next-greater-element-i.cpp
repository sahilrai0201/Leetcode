//APPROACH 1 : TC = O(N+M) & SC = O(N+M)--------------------------------------->
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;   // Stores: element -> next greater element

        // Traverse from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove all smaller or equal elements
            // They can never be the next greater element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists
            if (st.empty()) {
                mp[nums2[i]] = -1;
            }
            // Otherwise, top is the next greater element
            else {
                mp[nums2[i]] = st.top();
            }

            // Push current element for future comparisons
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Fetch answers for nums1 from the map
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};



//APPROACH 2 : TC = O(N*M) & SC = O(N)--------------------------------------->
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result;

//         for(int i=0; i<nums1.size(); i++){
//             int j;
//             for(j=0; j<nums2.size(); j++){
//                 if(nums2[j] == nums1[i]){
//                     break;
//                 }
//             }    
//             int nextGreater = -1;
//             for(int k=j+1; k<nums2.size(); k++){
//                 if(nums2[k] > nums1[i]){
//                     nextGreater = nums2[k];
//                     break;
//                 }
//             }
//             result.push_back(nextGreater);
//         }
//         return result;
//     }
// };