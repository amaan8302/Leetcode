class Solution {
public:
    int solve(vector<int>& nums, int target, int index, int sum, vector<vector<int>>& dp) 
    {
        if (index == nums.size()) 
        {
            if (target == sum)
                return 1;
            else 
                return 0;
        }
        if (dp[index][sum] != -1)
            return dp[index][sum];
        int plus = solve(nums, target, index + 1, sum + nums[index], dp);
        int minus = solve(nums, target, index + 1, sum - nums[index], dp);
        return dp[index][sum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return solve(arr, target + sum, 0, sum, dp);
    }
};