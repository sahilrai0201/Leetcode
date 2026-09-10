//APPROACH_3 : PRIORITY QUEUE -> TC = O(nlogk) & SC = O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums){

            // Add current element
            pq.push(num);

            // Keep only K elements in the heap
            if(pq.size() > k){
                pq.pop();
            }
        }

        // Smallest among the K largest elements
        // is the K-th largest element
        return pq.top();
    }
};



//APPROACH_2: EFFICIENT -> Tc = O(nlogn) & Sc = O(1)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k-1];
//     }
// };


//APPROACH_1: NOT EFFICIENT -> TC = O(nlogn) & SC = O(k)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         stack<int> st;

//         for(int i=0; i<k; i++){
//             st.push(nums[i]);
//         }
//         int ans = st.top();
//         st.pop();
//         return ans;
//     }
// };