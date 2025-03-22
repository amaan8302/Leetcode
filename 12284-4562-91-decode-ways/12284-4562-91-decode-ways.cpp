class Solution {
public:
    int solve(int i , string &s , int n,vector<int>&dp)
    {
        if(i==n)
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int one = solve(i+1,s,n,dp);
        int two = 0;
        if((s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))&&(i+1)<n)
            two = solve(i+2,s,n,dp);
        return dp[i] = one+two;
    }
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int n = s.length();
        if(n==1)
            return 1;
        vector<int>dp(n+1,-1);
        return solve(0,s,n,dp);
    }
};