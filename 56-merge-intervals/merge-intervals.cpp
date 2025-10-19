class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        //result vector
        vector<vector<int>> merged;

        //traverse intervals
        for(auto& interval : intervals){
            //if merged is empty or current interval does not overlap
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{
                //overlap case - merge them by updating end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};