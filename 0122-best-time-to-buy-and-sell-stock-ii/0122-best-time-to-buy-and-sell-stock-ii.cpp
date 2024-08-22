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
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};