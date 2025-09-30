class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Track minimum price so far
        int maxProfit = 0;        // Track maximum profit so far

        for (int price : prices) {
            minPrice = min(minPrice, price);             // Update min price
            maxProfit = max(maxProfit, price - minPrice); // Update profit
        }
        return maxProfit;
    }
};
