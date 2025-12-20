class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        //XOR all elements in the array!
        for(int x : nums){
            ans = ans ^ x;
        }
        return ans;
    }
}; 