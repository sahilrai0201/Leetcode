class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Get size of array
        int n = nums.size();

        // Initialize binary search pointers
        int start = 0, end = n-1;

        // Continue searching until start and end meet
        while(start < end){

            // Find middle index safely
            int mid = start + (end - start) / 2;

            // Make mid even so that pairs can be checked properly
            if(mid % 2 == 1){
                mid--;
            }

            // Valid pair found
            // Single element lies on right side
            if(nums[mid] == nums[mid + 1]){
                start = mid + 2;
            }
            else{
                // Pair pattern breaks
                // Single element lies at mid or left side
                end = mid;
            }
        }

        // start points to single non-duplicate element
        return nums[start];
    }
};