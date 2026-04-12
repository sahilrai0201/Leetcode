//APPROACH 2 : TC = O(N*M) & SC = O(N)--------------------------------------->
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for(int i=0; i<nums1.size(); i++){
            int j;
            for(j=0; j<nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    break;
                }
            }    
            int nextGreater = -1;
            for(int k=j+1; k<nums2.size(); k++){
                if(nums2[k] > nums1[i]){
                    nextGreater = nums2[k];
                    break;
                }
            }
            result.push_back(nextGreater);
        }
        return result;
    }
};


//APPROACH 1 : TC = O(N+M) & SC = O(N+M)--------------------------------------->
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         stack<int> st;
//         unordered_map<int,int> mp;

//         for(int i=nums2.size()-1; i>=0; i--){
//             while(!st.empty() && st.top() <= nums2[i]){
//                 st.pop();
//             }
//             if(st.empty()){
//                 mp[nums2[i]] = -1;
//             }
//             else{
//                 mp[nums2[i]] = st.top();
//             }
//             st.push(nums2[i]);
//         }
//         vector<int> ans;
//         for(int x : nums1){
//             ans.push_back(mp[x]);
//         }
//         return ans;
//     }
// };