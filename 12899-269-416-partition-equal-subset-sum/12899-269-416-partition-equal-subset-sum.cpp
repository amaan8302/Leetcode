class Solution {
public:
    bool solve(vector<int>& nums , int i , int tar,vector<vector<int>>&dp)
    {
        if(tar==0)
            return 1;
        if(i>=nums.size())
            return 0;
        if(dp[i][tar]!=-1)
            return dp[i][tar];
        bool take = 0;
        if(tar>=nums[i])
            take = solve(nums,i+1,tar-nums[i],dp);
        bool nottake = solve(nums,i+1,tar,dp);
        return dp[i][tar]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        int tar = sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(tar+1,-1));
        return solve(nums,0,tar,dp);
    }
};