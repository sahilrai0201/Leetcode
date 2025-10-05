class Solution {
private:
    void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {

        //base case
        if(index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;           //tracks numbers used at this recursive level
        for(int j=index; j<nums.size(); j++){
            if(used.count(nums[j])) continue;         //skip duplicates elements
            used.insert(nums[j]);

            swap(nums[index], nums[j]);
            solve(nums, index+1, ans);
            swap(nums[index], nums[j]);       //backtrack
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());        //helps group duplicates
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};