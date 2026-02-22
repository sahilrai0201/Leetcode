class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;      // stores index of previous '1' bit
        int maxGap = 0;     // stores maximum distance between consecutive 1s

        // i represents the current bit position (starting from LSB at index 0)
        for(int i = 0; n > 0; i++) {
            // Check if the least significant bit (LSB) is 1
            if(n & 1) {     
                // If this is NOT the first '1' encountered
                if(prev != -1) {
                    // Calculate distance between current '1' and previous '1'
                    // Update maxGap if this distance is larger
                    maxGap = max(maxGap, i - prev);
                }
                // Update prev to current position of '1'
                prev = i;
            }
            // Right shift n to check the next bit
            // This removes the current LSB and moves all bits right
            n = n >> 1;
        }
        // Return the maximum distance found
        return maxGap;
    }
};