class Solution {
public:
    int solve(int left, int right, vector<int>& cuts, vector<vector<int>>& dp) {
        if (right - left < 2)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        int result = INT_MAX;
        for (int i = left + 1; i < right; i++) {
            int cost = cuts[right] - cuts[left] + solve(left, i, cuts, dp) + solve(i, right, cuts, dp);
            result = min(result, cost);
        }
        return dp[left][right] = result;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));
        std::sort(cuts.begin(), cuts.end());
        return solve(0, m + 1, cuts, dp);
    }
};
