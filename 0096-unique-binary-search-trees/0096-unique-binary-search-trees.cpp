class Solution {
public:
    int solve(int n, vector<int>&dp)
    {
        if(n==0||n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int ans = 0;
        for(int i = 1 ; i <=n ; i++)//ye saare root nodes banengi, ek ek karke
            ans += solve(i-1,dp)*solve(n-i,dp);
        dp[n]=ans;
        return dp[n];
    }
    int solveTab(int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int j = 2 ; j <= n ; j ++)//j is number of nodes
        {
            // int ans = 0;
            for(int i = 1 ; i <=n ; i++)//ye saare root nodes banengi, ek ek karke
            {
                if(j>=i)
                    dp[j] += dp[i-1]*dp[j-i];
            }
            // dp[n]=ans;
        }
        return dp[n];
    }
    int numTrees(int n) 
    {
        // vector<int>dp(n+1,-1);
        return solveTab(n);
    }
};