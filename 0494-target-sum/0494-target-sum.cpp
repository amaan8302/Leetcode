class Solution {
public:
    // int solve(vector<int>& nums, int target,int index,vector<vector<int>>&dp)
    // {
    //     if(target == 0 && index == nums.size())
    //         return 1;
    //     if(index>=nums.size())
    //         return 0;
    //     if(dp[index][target]!=-1)
    //         return dp[index][target];
    //     int plus;
    //     plus = solve(nums,target-nums[index],index+1,dp);
    //     int minus = solve(nums,target+nums[index],index+1,dp);
    //     return dp[index][target]=plus+minus;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) 
    // {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i : nums)
    //         sum+=i;
    //     vector<vector<int>>dp(n+1,vector<int>(target+sum+1,-1));
    //     return solve(nums,target,0,dp);
    // }
    int solve(vector<int>& nums, int target,int index)
    {
        if(target == 0 && index == nums.size())
            return 1;
        if(index>=nums.size())
            return 0;
        int plus;
        plus = solve(nums,target-nums[index],index+1);
        int minus = solve(nums,target+nums[index],index+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return solve(nums,target,0);
    }
};