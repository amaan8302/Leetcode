class Solution {
public:
    int m, n;
    const int mod = 1e9 + 7;

    pair<long long, long long> solve(vector<vector<int>>& grid, int i, int j,vector<vector<pair<long long,long long>>>&dp) {
        if (i == m - 1 && j == n - 1)
            return {grid[i][j], grid[i][j]};
        long long maxVal = LLONG_MIN;
        long long minVal = LLONG_MAX;
        if(dp[i][j] != make_pair(LLONG_MIN,LLONG_MAX))
            return dp[i][j];
        if (i + 1 < m) {
            auto [downMax, downMin] = solve(grid, i + 1, j,dp);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(grid, i, j + 1,dp);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<pair<long long,long long>>>dp(m+1, vector<pair<long long,long long>>(n+1,{LLONG_MIN,LLONG_MAX}));
        auto [maxPro, minPro] = solve(grid, 0, 0,dp);
        return maxPro >= 0 ? maxPro % mod : -1;
    }
};
