class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        //start from the last digit
        for(int i=n-1; i>=0; i--){
            if(digits[i]<9){
                digits[i]++;    //no carry needed
                return digits;
            }
            digits[i]=0;     //carry over
        }
        //if all the digits were 9, we need an extra 1 at the front
        digits.insert(digits.begin(),1);
        return digits;
    }
};