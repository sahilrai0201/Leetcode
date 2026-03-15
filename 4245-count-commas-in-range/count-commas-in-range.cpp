class Solution {
public:
    int countCommas(int n) {
        int total = 0;  // stores total number of commas

        // Traverse every number from 1 to n
        for(int i = 1; i <= n; i++){
            int digits = 0;   // count digits of current number
            int x = i;        // copy of i for digit counting

            // Count digits in the number
            while(x){
                digits++;     // increase digit count
                x /= 10;      // remove last digit
            }

            // For every 3 digits after the first group we add a comma
            // (digits - 1) / 3 gives number of commas needed
            // Examples:
            // digits = 3 -> (3-1)/3 = 0 commas
            // digits = 4 -> (4-1)/3 = 1 comma
            // digits = 7 -> (7-1)/3 = 2 commas
            total += (digits - 1) / 3;
        }
        // return total commas required
        return total;
    }
};


//WRONG APPROACH : This codes checks commas in n only ->
// class Solution {
// public:
//     int countCommas(int n) {
//         if(n < 999) return 0;
//         else{
//             int count = 0;
//             int ans = 0;
            
//             while(n > 0){
//                 int digit = n % 10;
//                 count++;
//                 n = n / 10;
//             }
//             ans = count / 3;
//             return ans;
//         }
//     }
// };