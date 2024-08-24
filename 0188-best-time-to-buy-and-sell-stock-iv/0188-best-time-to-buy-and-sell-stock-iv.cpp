class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int transactionNum = 2*k-1 ; transactionNum>=0 ; transactionNum--)
            {
                int profit;
        
                if(transactionNum%2==0)//buy karna allowed he
                {
                    int buy = -prices[index]+dp[index+1][transactionNum+1];
                    int ignore = dp[index+1][transactionNum];
                    profit = max(buy,ignore); 
                }
                else
                {
                    int sell = dp[index+1][transactionNum+1]+prices[index];
                    int ignore = dp[index+1][transactionNum];
                    profit=max(sell,ignore);
                }
                dp[index][transactionNum]=profit;
            }
        }
        return dp[0][0];
    }
//     int maxProfit(int k, vector<int>& prices)
//     {
//         int n = prices.size();
//         vector<int>curr(2*k,0);
//         vector<int>curr(2*k,0);
        
//     }
};