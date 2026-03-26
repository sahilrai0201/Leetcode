class Solution {
public:
    // Function to check if it is safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        // Check the current row on the left side
        int x = row;
        int y = col;
        while(y >= 0){
            if(board[x][y] == 1){  // A queen already exists in this row
                return false;
            }
            y--;
        }

        // Check upper-left diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1){  // A queen exists on this diagonal
                return false;
            }
            y--;
            x--;
        }

        // Check lower-left diagonal
        x = row;
        y = col;
        while(x < n && y >= 0){
            if(board[x][y] == 1){  // A queen exists on this diagonal
                return false;
            }
            y--;
            x++;
        }

        // If no conflicts, it is safe to place the queen
        return true;
    }

    // Recursive function to try placing queens column by column
    int solve(int col, vector<vector<int>> &board, int n){
        // Base case: If all columns are filled, we found a valid solution
        if(col == n){
            return 1; // One valid solution found
        }

        int count = 0;  // To store number of valid solutions from this column

        // Try placing a queen in every row of this column
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){  // Check if it's safe
                board[row][col] = 1;         // Place the queen

                // Recur to place queens in the next column
                count += solve(col + 1, board, n);

                // Backtrack: remove the queen and try next row
                board[row][col] = 0;
            }
        }

        return count;  // Return total valid solutions found
    }

    // Main function to return total number of N-Queens solutions
    int totalNQueens(int n) {
        // Initialize an n x n board with all cells empty (0)
        vector<vector<int>> board(n, vector<int>(n, 0));

        // Start solving from the first column (0)
        return solve(0, board, n);
    }
};