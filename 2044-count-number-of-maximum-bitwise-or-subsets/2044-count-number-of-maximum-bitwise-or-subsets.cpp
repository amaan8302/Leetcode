class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = 0;
        for (int &i : nums) {
            n |= i;
        }
        int size = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            vector<int> temp = dp;
            for (int i = 0; i <= n; ++i)
            {
                if (dp[i]) 
                    temp[i | num] += dp[i];
            }
            dp = temp;
        }
        return dp[n];
    }
};
