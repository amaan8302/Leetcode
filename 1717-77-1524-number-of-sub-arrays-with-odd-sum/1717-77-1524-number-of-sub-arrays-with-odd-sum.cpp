class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int countSubarrays(int i, int odd, vector<int>& arr) {
        if (i < 0) return 0;
        if (dp[i][odd] != -1) return dp[i][odd];

        int res = 0;
        if (arr[i] % 2 == 1) 
        {
            if (odd)
                res = 1 + countSubarrays(i - 1, 0, arr);
            else
                res = countSubarrays(i - 1, 1, arr);
        }
        else 
        {
            if (odd)
                res = countSubarrays(i - 1, 1, arr);
            else
                res = 1 + countSubarrays(i - 1, 0, arr);
        }

        return dp[i][odd] = res % MOD;
    }
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(2, -1));
        int result = 0;
        for (int i = 0; i < n; i++)
            result = (result + countSubarrays(i, 1, arr)) % MOD;
        return result;
    }
};