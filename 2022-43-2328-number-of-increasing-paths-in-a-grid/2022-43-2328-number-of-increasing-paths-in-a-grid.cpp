class Solution {
public:
    int m,n;
    const int mod = 1e9+7;
    bool isSafe(int i,int j)
    {
        return (i<m && i>=0 && j<n && j>=0);
    }
    vector<vector<int>> directions = {{-1,0},{0,-1},{0,1},{1, 0}};
    int dfs(int i,int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 1;
        for(auto & k : directions)
        {
            int i1 = i + k[0];
            int j1 = j + k [1];
            if(isSafe(i1,j1)&& grid[i1][j1]<grid[i][j])
                ans = (ans + dfs(i1,j1,grid,dp))%mod; 
        }
        return dp[i][j] = ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int res = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                res = (res+dfs(i,j,grid,dp))%mod;
        }
        return res;
    }   
};  