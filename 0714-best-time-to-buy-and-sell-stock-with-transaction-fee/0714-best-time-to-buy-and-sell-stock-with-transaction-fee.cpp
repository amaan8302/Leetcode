class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index = n-1 ;index>=0;index--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                int profit;
                if(buy)
                {
                    int buyKaro = dp[index+1][0]-prices[index];
                    int ignore = dp[index+1][1];
                    profit = max(ignore,buyKaro);
                }
                else
                {
                    int sell = dp[index+1][1]+prices[index]-fee;
                    int ignore = dp[index+1][0];
                    profit = max(sell,ignore);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};