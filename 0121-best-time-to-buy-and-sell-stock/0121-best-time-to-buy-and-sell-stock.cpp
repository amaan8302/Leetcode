class Solution {
public:

    int solve(int i, vector<int>& prices, int mini,vector<int>&dp) {
        if (i == prices.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int profit = max(solve(i + 1, prices, min(mini, prices[i]),dp), prices[i] - mini);
        dp[i] = profit;
        return dp[i];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n+1,-1);
        return solve(0, prices, prices[0],dp);
    }
};
