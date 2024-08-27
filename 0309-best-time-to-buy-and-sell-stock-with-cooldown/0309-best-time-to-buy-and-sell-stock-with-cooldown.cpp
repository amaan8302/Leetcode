class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                if(buy)
                {
                    int buyK = -prices[index]+dp[index+1][0];
                    int ignore = dp[index+1][1];
                    dp[index][buy] = max(buyK,ignore); 
                }
                else
                {
                    int sell = dp[index+2][1]+prices[index];
                    int ignore = dp[index+1][0];
                    dp[index][buy]=max(sell,ignore);
                }
            }
        }
        return dp[0][1];
    }
};