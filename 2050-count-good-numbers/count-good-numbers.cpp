// TC = O(LOG N) & SC = O(LOG N) -------------------->

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Function to calculate (x^n) % MOD using Binary Exponentiation
    long long power(long long x, long long n){

        // Base Case :
        // Any number raised to the power 0 is 1
        if(n == 0){
            return 1;
        }

        // Recursively calculate x^(n/2)
        long long half = power(x, n / 2);

        // If exponent is even :
        // x^n = (x^(n/2)) * (x^(n/2))
        if(n % 2 == 0){
            return (half * half) % MOD;
        }

        // If exponent is odd:
        // x^n = x * (x^(n/2)) * (x^(n/2))
        return (x * (half * half) % MOD) % MOD;
    }

public:
    int countGoodNumbers(long long n) {

        // Number of even indices (0, 2, 4, ...)
        long long even = (n + 1) / 2;

        // Number of odd indices (1, 3, 5, ...)
        long long odd = n / 2;

        // Even indices have 5 choices: {0,2,4,6,8}
        // Odd indices have 4 choices: {2,3,5,7}

        // Total Good Numbers =
        // (5 ^ even) * (4 ^ odd)

        return (power(5, even) * power(4, odd)) % MOD;
    }
};