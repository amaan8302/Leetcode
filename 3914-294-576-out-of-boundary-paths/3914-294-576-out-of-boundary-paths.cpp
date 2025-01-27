class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int solve(int i , int j , int moves, int m , int n,vector<vector<vector<int>>>&dp)
    {
        if(i>=m || i<0 || j>=n || j<0)
            return 1;
        if(moves<=0)
            return 0;
        if(dp[i][j][moves]!=-1)
            return dp[i][j][moves];
        int res = 0;
        for(vector<int>&k : dir)
        {
            int nr = i + k[0];
            int nc = j + k[1];
            res = (res + solve(nr,nc,moves-1,m,n,dp))%mod;
        }
        // res = (res + solve(i,j+1,moves-1,m,n,dp)%mod + solve(i,j-1,moves-1,m,n,dp)%mod + solve(i+1,j,moves-1,m,n,dp)%mod+solve(i-1,j,moves-1,m,n,dp)%mod)%mod;
        return dp[i][j][moves] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove,m,n,dp);
    }
};