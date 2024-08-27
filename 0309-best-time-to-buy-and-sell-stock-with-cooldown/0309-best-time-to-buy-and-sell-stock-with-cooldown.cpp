class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                if(buy)
                {
                    int buyK = -prices[index]+curr[0];
                    int ignore = curr[1];
                    prev[buy] = max(buyK,ignore); 
                }
                else
                {
                    int sell = next[1]+prices[index];
                    int ignore = curr[0];
                    prev[buy]=max(sell,ignore);
                }
            }
            next = curr;
            curr=prev;
        }
        return curr[1];
    }
};