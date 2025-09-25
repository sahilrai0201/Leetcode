class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;          // base case
        return n/5 + trailingZeroes(n/5);  // count 5s and recurse
    }
};


/*
class Solution {

private:
    int fact(int n){
        if(n == 0 || n == 1) return 1;   //base case
        return n * fact(n - 1);          //recursive call
    }  

public:
    int trailingZeroes(int n) {

        int factorial = fact(n);       //compute factorial

        int count = 0;
        while(factorial % 10 == 0) {      //count trailing zeroes
            count++;
            factorial = factorial / 10;
            }
        return count;
    }
};
*/
