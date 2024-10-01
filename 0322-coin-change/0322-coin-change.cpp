class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = coinChangeHelper(coins, amount, dp);
        return (result == INT_MAX) ? -1 : result;
    }
    
    int coinChangeHelper(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];
        
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = coinChangeHelper(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
                mini = min(1 + ans, mini);
        }
        
        dp[amount] = mini;
        return mini;
    }
};
