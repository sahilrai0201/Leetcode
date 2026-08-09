// TC = O(1) & SC = O(1) ------------->
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};



// TC = O(LOGN) & SC = O(LOGN) ------------->
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         //base case
//         if(n == 1) return true;
//         if(n <= 0 || n % 2 != 0){
//             return false;
//         }

//         //recursive call
//         return isPowerOfTwo(n/2);
//     }
// };