//TC = O(N) & SC = O(1)----------->
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        //XOR all elements from 0 to n
        for(int i=0; i<=n; i++){
            ans = ans ^ i;
        }

        //XOR all elements of array
        for(int x : nums){
            ans = ans ^ x;
        }

        return ans;
    }
};