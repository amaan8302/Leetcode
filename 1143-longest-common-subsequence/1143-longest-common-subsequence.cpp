class Solution {
public:
    int solve(string &a, string &b,int i , int j,vector<vector<int>>&dp)
    {
        if(i==a.size()||j==b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            dp[i][j] = 1 + solve(a,b,i+1,j+1,dp);
        else
            dp[i][j] = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(text1,text2,0,0,dp);
    }
};