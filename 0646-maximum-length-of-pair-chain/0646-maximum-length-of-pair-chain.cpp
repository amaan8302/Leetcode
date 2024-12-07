class Solution {
public:
    int solve(vector<vector<int>>& p, int n, int curr, int prev, vector<vector<int>>& dp) {
        if (curr >= n)
            return 0;
        if (prev != -1 && dp[curr][prev] != -1)
            return dp[curr][prev];
        int incl = 0;
        if (prev == -1 || p[curr][0] > p[prev][1])
            incl = 1 + solve(p, n, curr + 1, curr, dp);
        int excl = solve(p, n, curr + 1, prev, dp);
        if (prev != -1)
            dp[curr][prev] = max(incl, excl);
        
        return max(incl, excl);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(pairs, n, 0, -1, dp);
    }
};