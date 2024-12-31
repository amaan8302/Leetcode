class Solution {
public:
    const int mod = 1e9+7;
    int solve(int low , int high , int z , int o, int len,vector<int>&dp)
    {
        if(len>high)
            return 0;
        int b = 0;
        if(len>=low)
            b = 1; 
        if(dp[len]!=-1)
            return dp[len];
        int zero = solve(low,high,z,o,len+z,dp);
        int one = solve(low,high,z,o,len+o,dp);
        return dp[len] = (b + zero + one)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int len = 0;
        vector<int>dp(high + 1, -1);
        return solve(low,high,zero,one,0,dp);
    }
};