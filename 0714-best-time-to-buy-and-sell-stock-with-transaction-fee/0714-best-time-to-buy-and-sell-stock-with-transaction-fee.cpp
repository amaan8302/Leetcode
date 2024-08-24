class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index = n-1 ;index>=0;index--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                int profit;
                if(buy)
                {
                    int buyKaro = next[0]-prices[index]-fee;
                    int ignore = next[1];
                    profit = max(ignore,buyKaro);
                }
                else
                {
                    int sell = next[1]+prices[index];
                    int ignore = next[0];
                    profit = max(sell,ignore);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
};