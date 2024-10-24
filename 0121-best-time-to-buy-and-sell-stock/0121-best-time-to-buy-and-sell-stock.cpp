class Solution {
public:
    vector<int> dp;
    
    int solve(int i, vector<int>& prices, int mini) {
        if (i == prices.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // Compute the profit for the current day and the next recursive call
        int profit = max(solve(i + 1, prices, min(mini, prices[i])), prices[i] - mini);
        
        // Memoize the result
        dp[i] = profit;
        return dp[i];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, -1);
        return solve(0, prices, prices[0]);
    }
};
