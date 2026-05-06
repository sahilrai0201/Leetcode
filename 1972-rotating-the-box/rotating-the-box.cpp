//TC = O(N*M) & SC = O(N*M) ----------------------------------------------------->
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();   //rows
        int m = boxGrid[0].size();    //columns

        for(int i=0; i<n; i++){
            int empty = m-1;
            for(int j=m-1; j>=0; j--){
                if(boxGrid[i][j] == '*'){
                    empty = j-1;
                }
                else if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        vector<vector<char>> rotated(m, vector<char>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rotated[j][n-1-i] = boxGrid[i][j];
            }
        }

        return rotated;
    }
};