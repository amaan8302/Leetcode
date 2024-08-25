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
    int longestPalindromeSubseq(string s) {
        
        string a = s;
        std::reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(a,s,0,0,dp);
    }
};