class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for(int i=0; i<numRows; i++) {
            ans[i].resize(i+1, 1);     //each row as i+1 elements & all initialized with 1

            //fill middle elements with the help of previous row
            for(int j=1; j<i; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};