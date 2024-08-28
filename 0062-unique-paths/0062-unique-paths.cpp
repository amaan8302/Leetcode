class Solution {
public:
    const int mod = 2000000000;
    int solve(int m , int n , vector<vector<int>>&dp, int i , int j)
    {
        if(i==0 || j==0)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]= (solve(m,n,dp,i-1,j)+solve(m,n,dp,i,j-1))%mod;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m,n,dp,m-1,n-1);
    }
};