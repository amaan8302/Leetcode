class Solution {
public:
    void addSolution(vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string row = "";
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1)
                    row += 'Q';
                else
                    row += '.';
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        // Check the same row on the left side
        for (int y = 0; y < col; y++) {
            if (board[row][y] == 1)
                return false;
        }

        // Check the upper diagonal on the left side
        for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) {
            if (board[x][y] == 1)
                return false;
        }

        // Check the lower diagonal on the left side
        for (int x = row, y = col; x < n && y >= 0; x++, y--) {
            if (board[x][y] == 1)
                return false;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
        // Base case: if all queens are placed
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        // Try placing queen in all rows one by one
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                // Place queen
                board[row][col] = 1;
                // Recur to place the rest of the queens
                solve(col + 1, ans, board, n);
                // Backtrack
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};
