class Solution {
public:
    void reverseParts(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 0 || n == 1) return;

        k = k % n;
        if(k == 0) return;

        reverseParts(nums, 0, n-1);
        reverseParts(nums, 0, k-1);
        reverseParts(nums, k, n-1);
    }
};





// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> temp(nums.size());
//         for(int i=0; i<nums.size(); i++){
//             temp[(i+k)%nums.size()]=nums[i];
//         }
//         nums=temp;
//     }
// };