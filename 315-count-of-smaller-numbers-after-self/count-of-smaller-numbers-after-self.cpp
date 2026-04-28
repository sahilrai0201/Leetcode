//TC = O(NlogN) & SC = O(N)------------------------------------------------------->
class Solution {
public:
    vector<int> ans;     // final answer
    vector<int> index;   // stores original positions

    // Merge two sorted parts
    void merge(vector<int>& nums, int left, int mid, int right) {

        vector<int> temp;      // temporary array for sorted indices

        int i = left;          // start of left half
        int j = mid + 1;      // start of right half

        int rightCount = 0;   // how many smaller right elements passed

        // compare both halves
        while (i <= mid && j <= right) {

            // if right value is smaller
            if (nums[index[j]] < nums[index[i]]) {

                temp.push_back(index[j]); // put right index
                rightCount++;             // one smaller found
                j++;

            } else {

                // add count to left element
                ans[index[i]] += rightCount;

                temp.push_back(index[i]); // put left index
                i++;
            }
        }

        // remaining left elements
        while (i <= mid) {

            ans[index[i]] += rightCount;
            temp.push_back(index[i]);
            i++;
        }

        // remaining right elements
        while (j <= right) {

            temp.push_back(index[j]);
            j++;
        }

        // copy back into index array
        for (int k = left; k <= right; k++) {
            index[k] = temp[k - left];
        }
    }

    // Normal merge sort
    void mergeSort(vector<int>& nums, int left, int right) {

        if (left >= right) return;

        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);       // left half
        mergeSort(nums, mid + 1, right);  // right half

        merge(nums, left, mid, right);    // merge both
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.assign(n, 0);   // all answers 0
        index.resize(n);

        // store original positions
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        mergeSort(nums, 0, n - 1);

        return ans;
    }
};




// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result;

//         for(int i=0; i<n; i++){
//             int count = 0;
//             for(int j=i+1; j<n; j++){
//                 if(nums[i] > nums[j]){
//                     count++;
//                 }
//             }
//             result.push_back(count);
//         }
//         return result;
//     }
// };