class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long a = nums[i];
                long long b = nums[j];
                long long t = (long long)target - a - b;
                int s = j+1, e = n-1;

                while(s<e){
                    long long sum = (long long)nums[s] + nums[e];
                    if(sum == t){
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        while(s<e && nums[s] == nums[s+1]) s++;
                        while(s<e && nums[e] == nums[e-1]) e--;
                        s++;
                        e--;
                    }
                    else if(sum > t){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
                while(i+1 < n && nums[i+1] == nums[i]) i++;
                while(j+1 < n && nums[j+1] == nums[j]) j++;
            }
        }
        return ans;
    }
};