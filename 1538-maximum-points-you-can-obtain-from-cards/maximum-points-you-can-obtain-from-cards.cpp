class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Calculate the total sum of all card points
        int total = 0;
        for (int x : cardPoints) {
            total += x;
        }

        // If we need to take all the cards,
        // simply return the total sum
        if (k == n) {
            return total;
        }

        // Size of the subarray that we will NOT take
        int window = n - k;

        // Calculate the sum of the first window
        int curr = 0;
        for (int i = 0; i < window; i++) {
            curr += cardPoints[i];
        }

        // Initialize the minimum window sum
        int mini = curr;

        // Slide the window across the array
        for (int i = window; i < n; i++) {

            // Add the new element entering the window
            curr += cardPoints[i];

            // Remove the element leaving the window
            curr -= cardPoints[i - window];

            // Update the minimum window sum
            mini = min(mini, curr);
        }

        // Maximum score = Total sum - Minimum window sum
        return total - mini;
    }
};








//class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();

//         int l = 0;
//         int score = 0;
//         int maxi = INT_MIN;

//         for(int r = 0; r < n; r++){
//             score += cardPoints[r];

//             maxi = max(maxi, score);

//             if(r - l + 1 >= k){
//                 score -= cardPoints[l];
//                 l++;
//             }
//         }

//         return maxi;
//     }
// };