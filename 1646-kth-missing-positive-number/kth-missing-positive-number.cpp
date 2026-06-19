// TC : O(log n)
// SC : O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        // Binary search range
        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Number of missing positive integers
            // before arr[mid]
            int missing = arr[mid] - (mid + 1);

            // If missing numbers till mid are less than k,
            // kth missing number lies on the right side
            if (missing < k) {
                low = mid + 1;
            }
            else {
                // We have found an index where
                // missing >= k, so search left
                // for the first such index
                high = mid - 1;
            }
        }

        // After binary search:
        // low = first index where missing >= k
        // Answer = k + low
        return low + k;
    }
};