// Time Complexity  : O(n × log(max(piles)))
// Space Complexity : O(1) 

class Solution {
public:

    // Function to check whether Koko can finish all bananas
    // within h hours if she eats at speed = k bananas/hour.
    bool canEat(vector<int>& piles, int h, int k) {

        // Total hours required at speed k
        long long hours = 0;

        // Traverse every pile
        for (int pile : piles) {

            // Ceiling division:
            // ceil(pile / k)
            // Example:
            // pile = 7, k = 3
            // hours needed = 3
            hours += (pile + k - 1) / k;

            // If required hours already exceed h,
            // no need to continue further.
            if (hours > h) {
                return false;
            }
        }

        // All piles can be finished within h hours
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible eating speed
        int low = 1;

        // Maximum possible eating speed
        // (eating the largest pile in one hour)
        int high = *max_element(piles.begin(), piles.end());

        // Store the minimum valid speed found so far
        int ans = high;

        // Binary Search on Answer
        while (low <= high) {

            // Candidate eating speed
            int mid = low + (high - low) / 2;

            // Check if Koko can finish all bananas
            // with speed = mid
            if (canEat(piles, h, mid)) {

                // mid is a valid answer
                ans = mid;

                // Try to find an even smaller valid speed
                high = mid - 1;
            }
            else {

                // mid is too slow
                // Need a larger eating speed
                low = mid + 1;
            }
        }

        // Smallest valid eating speed
        return ans;
    }
};