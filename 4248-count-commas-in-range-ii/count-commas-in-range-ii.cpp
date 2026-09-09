class Solution {
public:
    long long countCommas(long long n) {
        // Storing input in another variable (not really necessary,
        // but done here just to keep original value unchanged)
        long long nalverqito = n;

        long long ans = 0;      // stores total commas
        long long base = 1000;  // first number where comma appears (1,000)

        // We check ranges where commas appear
        // 1,000 → numbers have at least 1 comma
        // 1,000,000 → numbers have at least 2 commas
        // 1,000,000,000 → numbers have at least 3 commas

        while(base <= nalverqito){
            // Count how many numbers from base to n
            // Each of them contributes one comma at this level
            ans += nalverqito - base + 1;

            // Move to next comma level
            // 1000 → 1000000 → 1000000000 ...
            base *= 1000;
        }
        
        return ans;
    }
};