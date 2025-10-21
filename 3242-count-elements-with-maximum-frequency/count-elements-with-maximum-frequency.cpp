class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> count;
        int maxf = 0;

        for(int n : nums){
            count[n]++;
            maxf = max(maxf, count[n]);
        }
        int ans = 0;
        for(auto &p : count){
            if(p.second == maxf){
                ans = ans + p.second;
            }
        }
        return ans;
    }
};