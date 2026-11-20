//OPTIMISED VERSION ------------------------------------------------->
//TC = O(N) & SC = O(1) : 
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones = 0, zeros = 0;

        //Step 1 : count total occurrences of 1s and 0s
        for(char ch : s){
            if(ch == '1') ones++;
            else zeros++;
        }

        //Step 2 : Calculate the min flips for the four possible coherent patterns
        
        //CASE 1 : All 0's (flip all 1's)
        int allZeros = ones;


        //CASE 2 : All 1's (flip all 0's)
        int allOnes = zeros;

        //CASE 3 : At most one '1' (keep one '1' if it exists, flip the rest)
        int atMostOneOne = max(0, ones-1);

        // //CASE 4 : At most one '0' (keep one '0' if it exists, flip the rest)
        // int atMostOneZero = max(0, zeros-1);

        // CASE 4: 1 followed by all 0s and ending with 1
        int special = 0;

        if(s[0] != '1') special++;

        if(s[n-1] != '1') special++;

        for(int i = 1; i < n-1; i++){
            if(s[i] == '1'){
                special++;
            }
        }

        return min({allZeros, allOnes, atMostOneOne, special});
    }
};





//BRUTE FORCE ----------------------------------------------->
//TC = O(N*N) : 
// class Solution {
// public:
//     int minFlips(string s) {
//         int n = s.length();
//         int ans = n;

//         //try every split position
//         for(int split=0; split<=n; split++){

//             //CASE 1 : 000...111
//             int flips1 = 0;

//             //left part should be 0
//             for(int i=0; i<split; i++){
//                 if(s[i] == '1'){
//                     flips1++;
//                 }
//             }

//             //right part should be 1
//             for(int i=split; i<n; i++){
//                 if(s[i] == '0'){
//                     flips1++;
//                 }
//             }

//             //CASE 2 : 111...000
//             int flips2 = 0;

//             //left part should be 1
//             for(int i=0; i<split; i++){
//                 if(s[i] == '0'){
//                     flips2++;
//                 }
//             }

//             //right part should be 0
//             for(int i=split; i<n; i++){
//                 if(s[i] == '1'){
//                     flips2++;
//                 }
//             }

//             ans = min(ans, min(flips1, flips2));
//         }

//         return ans;
//     }
// };



