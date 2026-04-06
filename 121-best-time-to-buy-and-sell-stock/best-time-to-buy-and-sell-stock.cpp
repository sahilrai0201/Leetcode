//OPTIMISED APPROACH : TC = O(N) & SC = O(1)---------------->
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;

        for(int i=0; i<prices.size(); i++){
            min_price = min(prices[i], min_price);
            profit = max(profit, prices[i] - min_price);
        }
        return profit;
    }
};



//BRUTE FORCE : TC = O(N*N) & SC = O(1) -------------->
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int currProfit = 0;
//         int maxProfit = 0;

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 currProfit = prices[j] - prices[i];
//                 maxProfit = max(maxProfit, currProfit);
//             }
//         }
//         return maxProfit;
//     }
// };
