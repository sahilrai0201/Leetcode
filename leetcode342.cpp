class Solution {
public:
    bool isPowerOfFour(int n) {
        
        //base case
        if(n == 1) return true;
        if( n<=0 || n%4 != 0) {
            return false;
        }

        //recursive call
        return isPowerOfFour(n/4);

    }
};
