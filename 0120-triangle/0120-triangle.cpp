class Solution {
public:
    // int solve(vector<vector<int>>& triangle, int i , int j, int row,vector<vector<int>>&dp)
    // {
    //      if(row==1)
    //         return triangle[0][0];
    //     if(i>=row)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int first = triangle[i][j]+solve(triangle,i+1,j,row,dp);
    //     int second = triangle[i][j]+solve(triangle,i+1,j+1,row,dp);
    //     return dp[i][j] = min(first,second);
    // }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = 0 ; j <= i ; j++)
            {
                int first = triangle[i][j]+dp[i+1][j];
                int second = triangle[i][j]+dp[i+1][j+1];
                dp[i][j] = min(first,second);
            }
        }
        return dp[0][0];
    }
};