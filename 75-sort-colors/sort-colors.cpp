class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;

        //count 0s, 1s, 2s
        for(int x : nums){
            if(x == 0) zeroCount++;
            else if(x == 1) oneCount++;
            else twoCount++;
        }

        int i=0;

        // Rewrite array
        while (zeroCount--) nums[i++] = 0;
        while (oneCount--) nums[i++] = 1;
        while (twoCount--) nums[i++] = 2;
    }
};