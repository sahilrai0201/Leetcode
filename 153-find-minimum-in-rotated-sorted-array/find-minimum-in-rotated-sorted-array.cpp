class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        // Initialize binary search pointers
        int start = 0, end = n - 1;
        
        // Continue until start and end point to same element
        while(start < end){

            // Find middle index safely
            int mid = start + (end - start) / 2;

            // Minimum lies in right half
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{

                // Minimum lies at mid or in left half
                end = mid;
            }
        }

        // start points to minimum element
        return nums[start];
    }
};