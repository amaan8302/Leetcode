class Solution {
public:
    int solve(int index,int transactionNum,int k, vector<int>& prices,vector<vector<int>>&dp)
    {
        if(index==prices.size()||transactionNum>=2*k)
            return 0;
        if(dp[index][transactionNum]!=-1)
            return dp[index][transactionNum];
        int profit;
        
        if(transactionNum%2==0)//buy karna allowed he
        {
            int buy = -prices[index]+solve(index+1,transactionNum+1,k,prices,dp);
            int ignore = solve(index+1,transactionNum,k,prices,dp);
            profit = max(buy,ignore); 
        }
        else
        {
            int sell = solve(index+1,transactionNum+1,k,prices,dp)+prices[index];
            int ignore = solve(index+1,transactionNum,k,prices,dp);
            profit=max(sell,ignore);
        }
        return dp[index][transactionNum]=profit;
    }
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int transactionNum = 2*k-1 ; transactionNum>=0 ; transactionNum--)
            {
                int profit;
        
                if(transactionNum%2==0)//buy karna allowed he
                {
                    int buy = -prices[index]+solve(index+1,transactionNum+1,k,prices,dp);
                    int ignore = solve(index+1,transactionNum,k,prices,dp);
                    profit = max(buy,ignore); 
                }
                else
                {
                    int sell = solve(index+1,transactionNum+1,k,prices,dp)+prices[index];
                    int ignore = solve(index+1,transactionNum,k,prices,dp);
                    profit=max(sell,ignore);
                }
                dp[index][transactionNum]=profit;
            }
        }
        return dp[0][0];
    }
    // int maxProfit(int k, vector<int>& prices)
    // {
    //     int n = prices.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2*k,-1));
    //     return solve(0,0,k,prices,dp);    
    // }
};