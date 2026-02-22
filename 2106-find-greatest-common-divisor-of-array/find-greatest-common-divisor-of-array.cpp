//TC : O(n) ->
class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int num : nums){
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        return gcd(mini, maxi);
    }
};



//TC : O(nlogn) -> 
// class Solution {
// public:
//     int gcd(int a, int b){
//         if(b == 0) return a;
//         return gcd(b, a % b);
//     }
//     int findGCD(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int smallest = nums[0];
//         int largest = nums[n-1];

//         int result = gcd(smallest, largest);
//         return result;
//     }
// };