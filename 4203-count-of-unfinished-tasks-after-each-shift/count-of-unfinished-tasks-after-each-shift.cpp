// Time Complexity: \(O(n + m\log n)\)
// Auxiliary Space Complexity: \(O(n)\) for the prefix sum array.

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        // Building prefix sum to calculate the total time required
        // to complete the first i tasks.
        vector<long long> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + tasks[i];
        }

        vector<int> ans;

        // Stores the total working time accumulated so far
        // in the current round of tasks.
        long long done = 0;

        for(long long t : shifts) {

            // Add the available working time of the current shift.
            done += t;

            // If all tasks are completed, store 0 unfinished tasks
            // and reset the progress for the next round.
            if(done >= pref[n]) {
                ans.push_back(0);
                done = 0;
            }
            else {
                // Find the first prefix sum strictly greater than done.
                // This tells us where the next unfinished task starts.
                int pos = upper_bound(pref.begin(), pref.end(), done)
                          - pref.begin();

                // Number of completely completed tasks.
                int completed = pos - 1;

                // Remaining tasks = Total tasks - Completed tasks.
                ans.push_back(n - completed);
            }
        }

        return ans;
    }
};
