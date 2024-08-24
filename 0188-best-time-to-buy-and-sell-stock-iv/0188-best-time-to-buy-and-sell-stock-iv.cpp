class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<int>curr(2*k+1,0);
        vector<int>next(2*k+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int transactionNum = 2*k-1 ; transactionNum>=0 ; transactionNum--)
            {
                int profit;
        
                if(transactionNum%2==0)//buy karna allowed he
                {
                    int buy = -prices[index]+next[transactionNum+1];
                    int ignore =next[transactionNum];
                    profit = max(buy,ignore); 
                }
                else
                {
                    int sell = next[transactionNum+1]+prices[index];
                    int ignore = next[transactionNum];
                    profit=max(sell,ignore);
                }
                curr[transactionNum]=profit;
            }
            next=curr;
        }
        return next[0];
    }
};