class Solution {
public:
    int solve(vector<int>& prices,int index,bool buy,vector<vector<int>>&dp)
    {
        int n = prices.size();
        if(index==n)
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int profit;
        if(buy)
        {
            int buy = -prices[index]+solve(prices,index+1,0,dp);
            int ignore = solve(prices,index+1,1,dp);
            profit = max(buy,ignore); 
        }
        else
        {
            int sell = solve(prices,index+1,1,dp)+prices[index];
            int ignore = solve(prices,index+1,0,dp);
            profit=max(sell,ignore);
        }
        return dp[index][buy]=profit;
    }
    int solveTab(vector<int>& prices,bool buy)
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index = n-1 ; index>=0 ; index--)
        {
            dp[index][0]=max(dp[index+1][1]+prices[index],dp[index+1][0]);
            dp[index][1]=max(dp[index+1][0]-prices[index],dp[index+1][1]);
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) 
    {
        // int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(prices,0,1,dp);
        return solveTab(prices,1);
    }
};