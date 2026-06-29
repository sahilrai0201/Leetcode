class Solution {
public:

    bool isPossible(vector<int>& nums, int k, int split){
        int n = nums.size();

        int subarray = 1;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(sum + nums[i] <= split){
                sum += nums[i];
            }
            else{
                subarray++;
                sum = nums[i];

                if(subarray > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(nums, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};