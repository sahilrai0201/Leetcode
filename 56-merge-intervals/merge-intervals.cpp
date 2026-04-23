// TC = O(N log N)   -> sorting
// SC = O(N)         -> result vector

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());   // sort by start time

        vector<vector<int>> result;
        int n = intervals.size();

        int start = intervals[0][0];   // first interval start
        int end = intervals[0][1];     // first interval end

        for(int i = 0; i < n; i++) {

            // if overlap exists
            if(end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);   // extend end
            }
            else {
                result.push_back({start, end});    // store merged interval

                start = intervals[i][0];           // new start
                end = intervals[i][1];             // new end
            }
        }

        result.push_back({start, end});   // push last interval

        return result;
    }
};
