class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        int n, j = 0;
        long long res = 0;
        unordered_map<int, int> mp;
        n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = nums[i] - i;

        while (j < n) {
            res += j - mp[ans[j]];
            mp[ans[j]]++;
            j++;
        }
        return res;
    }
};