class Solution {
public:

    // Checks whether it is possible to make at least m bouquets
    // if we wait for 'days' number of days.
    bool canMake(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;  // Number of bouquets formed
        int count = 0;     // Count of consecutive bloomed flowers

        for (int bloom : bloomDay) {

            // Flower has bloomed by 'days'
            if (bloom <= days) {
                count++;
            }
            else {
                // Break in adjacency, reset count
                count = 0;
            }

            // If we have k consecutive flowers,
            // form one bouquet
            if (count == k) {
                bouquets++;

                // Reset count because flowers used in
                // this bouquet cannot be reused
                count = 0;
            }
        }

        // Check if we can make at least m bouquets
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Total flowers required to make m bouquets
        long long flowersNeeded = 1LL * m * k;

        // Not enough flowers available
        if (flowersNeeded > n)
            return -1;

        // Binary search range:
        // minimum bloom day to maximum bloom day
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary Search on answer
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If possible to make bouquets in 'mid' days,
            // try finding a smaller answer
            if (canMake(bloomDay, m, k, mid)) {
                high = mid - 1;
            }
            else {
                // Not possible, need more days
                low = mid + 1;
            }
        }

        // low points to the minimum valid day
        return low;
    }
};