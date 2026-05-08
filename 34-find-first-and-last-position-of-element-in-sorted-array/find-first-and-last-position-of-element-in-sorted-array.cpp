//APPROACH 2 : TC = O(logN) & SC = O(1) -------------------------------------------->
class Solution {
public:

    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int lastOcc(vector<int>& nums, int target){
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);

        return {first, last};
    }
};





//APPROACH 1 : TC = O(N) & SC = O(1) -------------------------------------------->
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
        
//         int firstOcc = -1;
//         int lastOcc = -1;

//         for(int i=0; i<n; i++){
//             if(nums[i] == target){

//                 //store first occurence only one
//                 if(firstOcc == -1){
//                     firstOcc = i;
//                 }

//                 //keep updating last occ
//                 lastOcc = i;
//             }
//         }

//         return {firstOcc, lastOcc};
//     }
// };