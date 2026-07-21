class Solution {
public:
    // Check whether 'val' can be placed at (row, col)
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {

        for (int i = 0; i < 9; i++) {

            // Check current row
            if (board[row][i] == val)
                return false;

            // Check current column
            if (board[i][col] == val)
                return false;

            // Check corresponding 3x3 subgrid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }

        // Safe to place
        return true;
    }

    bool solve(vector<vector<char>>& board) {

        int n = board.size();

        // Traverse the entire board
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                // Process only empty cells
                if (board[row][col] == '.') {

                    // Try every digit from 1 to 9
                    for (char val = '1'; val <= '9'; val++) {

                        // If current digit can be placed
                        if (isSafe(row, col, board, val)) {

                            // Choose
                            board[row][col] = val;

                            // Explore remaining board
                            if (solve(board))
                                return true;

                            // Undo the choice (Backtrack)
                            board[row][col] = '.';
                        }
                    }

                    // No digit worked for this cell
                    return false;
                }
            }
        }

        // No empty cell left -> Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};