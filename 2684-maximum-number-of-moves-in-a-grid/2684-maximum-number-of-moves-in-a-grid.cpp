class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, int currVal,vector<vector<int>>&dp) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= currVal)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        currVal = grid[i][j];
        int first = 1 + solve(grid, i - 1, j + 1, m, n, currVal,dp);
        int second = 1 + solve(grid, i, j + 1, m, n, currVal,dp);
        int third = 1 + solve(grid, i + 1, j + 1, m, n, currVal,dp);

        return dp[i][j]=max({first, second, third});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        int res = 0; 
        for (int i = 0; i < m; i++) {
            res = max(res, solve(grid, i, 0, m, n, -1,dp));
        }
        return res - 1;
    }
};
