class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m,vector<vector<int>>&dp) 
    {
        if(i < 0 || j < 0 || i >= n || j >= m) 
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int current = matrix[i][j];
        int maxPath = 1;
        if(i-1 >= 0 && matrix[i-1][j] > current)
            maxPath = max(maxPath, 1 + solve(matrix, i-1, j, n, m,dp));
        if(i+1 < n && matrix[i+1][j] > current)
            maxPath = max(maxPath, 1 + solve(matrix, i+1, j, n, m,dp));
        if(j-1 >= 0 && matrix[i][j-1] > current)
            maxPath = max(maxPath, 1 + solve(matrix, i, j-1, n, m,dp));
        if(j+1 < m && matrix[i][j+1] > current)
            maxPath = max(maxPath, 1 + solve(matrix, i, j+1, n, m,dp));
        return dp[i][j]=maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, solve(matrix, i, j, n, m,dp));
            }
        }
        return ans;
    }

};