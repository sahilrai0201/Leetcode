class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (but not 0 itself) are not palindromes
        if(x<0 ||  (x%10==0 && x!=0)){
            return false;
        }
        int reversedHalf=0;
        while(x>reversedHalf){
            reversedHalf = reversedHalf*10 + x%10;
            x=x/10;
        }
        // If x is equal to reversedHalf (even length)
        // or x is equal to reversedHalf/10 (odd length, middle digit ignored)
        return (x==reversedHalf || x==reversedHalf/10);
    }
};