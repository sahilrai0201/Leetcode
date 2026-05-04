class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        //transpose of the matrix
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse the trasposed matrix manually
        //ROW REVERSAL FOR CLOCKWISE ROTATION----->
        for(int i=0; i<n; i++){
            int left = 0, right = n-1;
            while(left < right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }

        // //reverse the transposed matrix usaing STL
        // for(int i=0; i<n; i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }
        
    }
};

//TC = O(N*N) & SC = O(1)--------------------->