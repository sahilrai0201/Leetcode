//TC = O(NlogN) & SC = O(N)------------------------------------->
//Sort the array while counting valid pairs efficiently using two pointers during merge
class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right){
        int count = 0;
        int j = mid + 1;

        //count reverse pairs
        for(int i=left; i<=mid; i++){
            while(j <= right && nums[i] > 2LL * nums[j]){
                j++;
            }
            count += (j - (mid + 1));
        }

        //merge step
        vector<int> temp;
        int i = left, k = mid+1;

        while(i<=mid && k<=right){
            if(nums[i] <= nums[k]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[k++]);
            }
        }

        while(i<=mid) temp.push_back(nums[i++]);
        while(k<=right) temp.push_back(nums[k++]);

        //copy back to original array
        for(int p=left; p<=right; p++){
            nums[p] = temp[p-left];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right){
        if(left >= right) return 0;

        int mid = (left + right) / 2;
        int count = 0;

        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid+1, right);
        count += merge(nums, left, mid, right);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};




//TC = O(N*N)------------Brute Force-------------------------->
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(nums[i] > 2*nums[j]){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };