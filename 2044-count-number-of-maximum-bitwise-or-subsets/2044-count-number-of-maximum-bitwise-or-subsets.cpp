class Solution {
public:
    int solve(int i , int curr, vector<int>& nums, int n,vector<vector<int>>&dp)
    {
        if(i==nums.size())
        {
            if(curr==n)
                return 1;
            return 0;
        }
        if(dp[i][curr]!=-1)
            return dp[i][curr];
        int take = solve(i+1,curr|nums[i],nums,n,dp);
        int no = solve(i+1,curr,nums,n,dp);
        return dp[i][curr]=take+no;
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = 0;
        for(int &i : nums)
            n |=i;
        vector<vector<int>>dp(nums.size()+1,vector<int>(n+1,-1));
        int curr = 0;
        return solve(0,curr,nums,n,dp);
    }
};