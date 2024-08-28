class Solution {
public:
    const int mod = 2000000000;
    int solve(vector<vector<int>>& obstacleGrid, int i , int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
            return 1;
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j] = solve(obstacleGrid,i-1,j,dp)+solve(obstacleGrid,i,j-1,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int>>dp(m+1,vector<int>(n,-1));
        return solve(obstacleGrid,m-1,n-1,dp);
    }
};