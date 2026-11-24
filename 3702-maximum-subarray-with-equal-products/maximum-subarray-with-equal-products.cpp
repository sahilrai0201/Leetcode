// TC = O(n²)
// SC = O(1)

class Solution {
public:
    // Generate a bitmask of prime factors
    int getMask(int x) {
        int mask = 0;
        int primes[] = {2, 3, 5, 7};

        for(int i = 0; i < 4; i++) {
            if(x % primes[i] == 0) {
                mask |= (1 << i);
            }
        }

        return mask;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        // Step 1: Every subarray of length 2 is valid
        if(n >= 2) ans = 2;

        // Step 2: Try every starting index
        for(int i = 0; i < n; i++) {

            // Store prime factors already encountered
            int usedMask = getMask(nums[i]);

            // Check whether the first two elements are coprime
            if(i + 1 < n) {
                int mask = getMask(nums[i + 1]);

                if(usedMask & mask) {
                    continue;
                }

                usedMask |= mask;
            }

            // Step 3: Extend subarray from the third element
            for(int j = i + 2; j < n; j++) {

                int mask = getMask(nums[j]);

                // Check whether any prime factor is repeated
                if(usedMask & mask) {
                    break;
                }

                // Add current element's prime factors
                usedMask |= mask;

                // Update maximum length
                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};





// TC = O(n² × log M)
// SC = O(1)

// class Solution {
// public:
//     int maxLength(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;

//         // Step 1: Try every possible starting index
//         for(int i = 0; i < n; i++) {

//             long long product = 1;
//             int gcdVal = 0;
//             long long lcmVal = 1;

//             // Step 2: Generate all subarrays starting from index i
//             for(int j = i; j < n; j++) {

//                 // Calculate product of all elements in the subarray
//                 product *= nums[j];

//                 // Update GCD of the current subarray
//                 gcdVal = gcd(gcdVal, nums[j]);

//                 // Update LCM of the current subarray
//                 lcmVal = lcm(lcmVal, (long long)nums[j]);

//                 // Step 3: Check if Product = GCD * LCM
//                 if(product == gcdVal * lcmVal) {

//                     // Update maximum length of valid subarray
//                     ans = max(ans, j - i + 1);
//                 }
//             }
//         }

//         // Step 4: Return the maximum valid subarray length
//         return ans;
//     }
// };