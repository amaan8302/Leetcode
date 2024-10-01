class Solution {
public:
    int solve(vector<vector<int>>& grid,int row,int col,int m,int n,vector<vector<int>>&dp)
    {
        if(row>=m || col>=n)
            return 515195999;
        if (row == m - 1 && col == n - 1)
            return grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int down = grid[row][col] + solve(grid,row+1,col,m,n,dp);
        int right = grid[row][col] + solve(grid,row,col+1,m,n,dp);
        return dp[row][col]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();  
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(grid,0,0,m,n,dp);
    }
};