class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>next(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int index = n-1 ; index>=0 ; index--)
        {
            for(int buy = 0 ; buy <= 1;buy++)
            {
                for(int limit = 1 ; limit <=2 ;limit++)
                {
                    int profit;
                    if(buy)
                    {
                        int buy = -prices[index]+next[0][limit];
                        int ignore = next[1][limit];
                        profit = max(buy,ignore); 
                    }
                    else
                    {
                        
                        int sell = next[1][limit-1]+prices[index];
                        int ignore = next[0][limit];
                        profit=max(sell,ignore);
                    }
                    curr[buy][limit]=profit;
                }
                next=curr;
            }
        }
        return next[1][2];
    }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
//         for(int index = n-1 ; index>=0 ; index--)
//         {
//             for(int buy = 0 ; buy <= 1;buy++)
//             {
//                 for(int limit = 1 ; limit <=2 ;limit++)
//                 {
//                     int profit;
//                     if(buy)
//                     {
//                         int buy = -prices[index]+dp[index+1][0][limit];
//                         int ignore = dp[index+1][1][limit];
//                         profit = max(buy,ignore); 
//                     }
//                     else
//                     {
                        
//                         int sell = dp[index+1][1][limit-1]+prices[index];
//                         int ignore = dp[index+1][0][limit];
//                         profit=max(sell,ignore);
//                     }
//                     dp[index][buy][limit]=profit;
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
};