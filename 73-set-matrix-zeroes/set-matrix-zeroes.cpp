class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> zeroes;

        // Step 1: store positions of all zeros
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i, j});
                }
            }
        }
        
        // Step 2: mark rows and columns as zero
        for(auto it : zeroes){
            int row = it.first;
            int col = it.second;

            // make entire row zero
            for(int j=0; j<m; j++){
                matrix[row][j] = 0;
            }

            // make entire column zero
            for(int i=0; i<n; i++){
                matrix[i][col] = 0;
            }
        }
    }
};