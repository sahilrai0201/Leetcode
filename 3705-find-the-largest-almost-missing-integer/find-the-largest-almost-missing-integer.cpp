class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; i++) positions[nums[i]].push_back(i);

        int answer = -1;

        for (auto& [value, idxs] : positions) {
            // valid window starts (0 to n-k) that contain at least one occurrence
            set<int> starts;
            for (int i : idxs) {
                int lo = max(0, i - k + 1);
                int hi = min(i, n - k);
                for (int s = lo; s <= hi; s++) starts.insert(s);
            }
            if ((int)starts.size() == 1) {
                answer = max(answer, value);
            }
        }
        return answer;
    }
};