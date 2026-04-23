class Solution {
public:
    vector<int> ans;
    vector<int> index;

    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right) return;

        int mid = (left + right)/2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp;
        int i = left, j = mid + 1;
        int rightCount = 0;

        while(i <= mid && j <= right){
            if(nums[index[j]] < nums[index[i]]) {
                temp.push_back(index[j]);
                rightCount++;
                j++;
            } else {
                ans[index[i]] += rightCount;
                temp.push_back(index[i]);
                i++;
            }
        }

        while(i <= mid) {
            ans[index[i]] += rightCount;
            temp.push_back(index[i]);
            i++;
        }

        while(j <= right) {
            temp.push_back(index[j]);
            j++;
        }

        for(int k = left; k <= right; k++) {
            index[k] = temp[k - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        index.resize(n);

        for(int i=0; i<n; i++) index[i] = i;

        mergeSort(nums, 0, n-1);
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