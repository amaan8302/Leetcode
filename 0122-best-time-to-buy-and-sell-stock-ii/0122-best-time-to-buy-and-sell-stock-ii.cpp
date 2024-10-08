class Solution {
public:
    // int solveTab(vector<int>& prices)
    // {
    //     int n = prices.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2,0));
    //     for(int index = n-1 ; index>=0 ; index--)
    //     {
    //         dp[index][0]=max(dp[index+1][1]+prices[index],dp[index+1][0]);
    //         dp[index][1]=max(dp[index+1][0]-prices[index],dp[index+1][1]);
    //     }
    //     return dp[0][1];
    // }
    int solve(vector<int>& prices)
    {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index = n-1 ; index>=0 ; index--)
        {
            curr[0]=max(next[1]+prices[index],next[0]);
            curr[1]=max(next[0]-prices[index],next[1]);
            next=curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};