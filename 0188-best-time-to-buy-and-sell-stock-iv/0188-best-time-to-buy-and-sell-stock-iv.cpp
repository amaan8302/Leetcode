class Solution {
public:
    // int solve(vector<int>& prices,int index,bool buy,int limit,vector<vector<vector<int>>>&dp)
    // {
    //     int n = prices.size();
    //     if(index==n||limit==0)
    //         return 0;
    //     if(dp[index][buy][limit]!=-1)
    //         return dp[index][buy][limit];
    //     int profit;
    //     if(buy)
    //     {
    //         int buy = -prices[index]+solve(prices,index+1,0,limit,dp);
    //         int ignore = solve(prices,index+1,1,limit,dp);
    //         profit = max(buy,ignore); 
    //     }
    //     else
    //     {
    //         int sell = solve(prices,index+1,1,limit-1,dp)+prices[index];
    //         int ignore = solve(prices,index+1,0,limit,dp);
    //         profit=max(sell,ignore);
    //     }
    //     // return solve(prices,0,1,k,dp);
    //     return dp[index][buy][limit]=profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+2,0)));
        for(int index = n-1 ; index>=0 ; index--)
        {
            for(int buy = 0 ; buy <=1 ; buy++)
            {
                for(int limit = 1 ; limit<=k;limit++)
                {
                    int profit;
                    if(buy)
                    {
                        int buy = -prices[index]+dp[index+1][0][limit];
                        int ignore = dp[index+1][1][limit];
                        profit = max(buy,ignore); 
                    }
                    else
                    {
                        int sell = dp[index+1][1][limit-1]+prices[index];
                        int ignore = dp[index+1][0][limit];
                        profit=max(sell,ignore);
                    }
                    dp[index][buy][limit]=profit;   
                }
            }
        }
        return dp[0][1][k];
    }
};