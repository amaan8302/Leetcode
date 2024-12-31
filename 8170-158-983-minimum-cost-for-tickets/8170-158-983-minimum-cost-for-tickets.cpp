class Solution {
public:
    int bs(vector<int>& nums, int tar) 
    {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= tar)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    int solve(vector<int>& days, vector<int>& cost, int i, vector<int>& dp) {
        if (i >= days.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int first = cost[0] + solve(days, cost, i + 1, dp);
        int second = cost[1] + solve(days, cost, bs(days, days[i] + 7), dp);
        int third = cost[2] + solve(days, cost, bs(days, days[i] + 30), dp);
        return dp[i] = min({first, second, third});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, costs, 0, dp);
    }
};