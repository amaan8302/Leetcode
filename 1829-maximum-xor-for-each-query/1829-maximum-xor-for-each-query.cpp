class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n = nums.size();
        vector<int>res;
        int x = 0;
        for(int i : nums)
            x = x^i;
        int mask = (1<<maximumBit)-1;
        for(int i = 0 ; i < n ; i++)
        {
            int ans = x^mask;
            res.push_back(ans);
            x = x^nums[n-i-1];
        }
        return res;
    }
};