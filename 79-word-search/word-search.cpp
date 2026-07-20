class Solution {
private:
    // DFS function to check whether the word can be formed
    // starting from board[row][col] and matching word[index...]
    bool dfs(vector<vector<char>>& board, string &word,
             int row, int col, int index) {

        // Base Case:
        // If all characters of the word have been matched,
        // then we have successfully found the word.
        if (index == word.length()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // Invalid Case 1:
        // Current cell is outside the board.
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return false;
        }

        // Invalid Case 2:
        // Current board character does not match
        // the current character of the word.
        if (board[row][col] != word[index]) {
            return false;
        }

        // Save the original character before marking it visited.
        char ch = board[row][col];

        // Mark this cell as visited so it cannot be reused
        // in the current path.
        board[row][col] = '#';

        // Explore all four possible directions.
        bool found =
            dfs(board, word, row - 1, col, index + 1) ||   // Up
            dfs(board, word, row + 1, col, index + 1) ||   // Down
            dfs(board, word, row, col - 1, index + 1) ||   // Left
            dfs(board, word, row, col + 1, index + 1);     // Right

        // Backtracking:
        // Restore the original character so this cell
        // can be used in another possible path.
        board[row][col] = ch;

        // Return whether any of the four paths succeeded.
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        // Since the first letter of the word can be anywhere,
        // try every cell as the starting point.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start DFS only if the first character matches.
                if (board[i][j] == word[0]) {

                    // If any DFS returns true,
                    // the word exists in the board.
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        // Word cannot be formed from any starting position.
        return false;
    }
};