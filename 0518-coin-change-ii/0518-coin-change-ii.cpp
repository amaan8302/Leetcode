class Solution {
public:
    int solve(int i, int amount,vector<int>& coins,int n,vector<vector<int>>&dp)
    {
        if(amount==0)
            return 1;
        if(i>=n)
            return 0;
        if(coins[i]>amount)
            return solve(i+1,amount,coins,n,dp);
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int take = solve(i,amount - coins[i] , coins,n,dp);
        int skip = solve(i+1 , amount , coins,n,dp);
        return dp[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins,n,dp);
    }
};