class Solution {
public:

    // Returns the column index of the maximum element in a row
    int maxCol(vector<int> &row) {
        int idx = 0;  // Assume first element is the largest

        // Find the index of the maximum element
        for (int i = 1; i < row.size(); i++) {
            if (row[i] > row[idx]) {
                idx = i;
            }
        }

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        // Binary search on rows
        int low = 0;
        int high = mat.size() - 1;

        while (low < high) {

            // Find the middle row
            int mid = low + (high - low) / 2;

            // Find the column containing the maximum element in the middle row
            int j = maxCol(mat[mid]);

            // Compare the maximum element with the element directly below it
            if (mat[mid][j] > mat[mid + 1][j]) {
                // Peak lies in the upper half (including mid)
                high = mid;
            }
            else {
                // Peak lies in the lower half
                low = mid + 1;
            }
        }

        // 'low' is now the row containing a peak.
        // Return its row index and the column index of its maximum element.
        return {low, maxCol(mat[low])};
    }
};