class Solution {
public:
    int solve(vector<int>& prices)
    {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index = n-1 ; index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit;
                if(buy)
                {
                    int b = -prices[index]+next[0];
                    int ignore = next[1];
                    profit = max(b,ignore); 
                }
                else
                {
                    int sell = next[1]+prices[index];
                    int ignore = next[0];
                    profit=max(sell,ignore);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};