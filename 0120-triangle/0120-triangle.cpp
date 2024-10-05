class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i , int j, int row,vector<vector<int>>&dp)
    {
         if(row==1)
            return triangle[0][0];
        if(i>=row)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int first = triangle[i][j]+solve(triangle,i+1,j,row,dp);
        int second = triangle[i][j]+solve(triangle,i+1,j+1,row,dp);
        return dp[i][j] = min(first,second);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int row = triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
        return solve(triangle,0,0,row,dp);
        // vector<vector<int>>dp(row+1,vector<int>(row+1,0));
        // for(int i = 0 ; i < row ; i++)
        // {
        //     dp[row]
        // }
    }
};