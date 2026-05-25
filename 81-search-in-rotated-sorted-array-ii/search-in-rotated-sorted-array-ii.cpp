// OPTIMISED BINARY SEARCH APPROACH : TC = O(log N) & SC = O(1) ------------------->
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        // Initialize two pointers for binary search
        int start = 0, end = n-1;

        // Continue searching while search space is valid
        while(start <= end){

            // Find middle index safely
            int mid = start + (end - start) / 2;

            // Target found
            if(nums[mid] == target){
                return true;
            }

            // Handle duplicates
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
            }

            // Check if left half is sorted
            else if(nums[mid] >= nums[start]){

                // Check if target lies in left sorted half
                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    // Otherwise search in right half
                    start = mid + 1;
                }
            }
            else{

                // Right half is sorted
                // Check if target lies in right sorted half
                if(target > nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    // Otherwise search in left half
                    end = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};