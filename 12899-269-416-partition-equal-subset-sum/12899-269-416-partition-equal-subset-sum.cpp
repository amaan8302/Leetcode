class Solution {
public:
    // bool solve(vector<int>& nums , int i , int tar,vector<vector<int>>&dp)
    // {
    //     if(tar==0)
    //         return 1;
    //     if(i>=nums.size())
    //         return 0;
    //     if(dp[i][tar]!=-1)
    //         return dp[i][tar];
    //     bool take = 0;
    //     if(tar>=nums[i])
    //         take = solve(nums,i+1,tar-nums[i],dp);
    //     bool nottake = solve(nums,i+1,tar,dp);
    //     return dp[i][tar]=take||nottake;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(int i : nums)
    //         sum+=i;
    //     if(sum%2!=0)
    //         return false;
    //     int tar = sum/2;
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(tar+1,-1));
    //     return solve(nums,0,tar,dp);
    // }
    bool canPartition(vector<int>& nums){
        int sum = 0;
        for(int i : nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        int target = sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        for(int i = 0 ; i <= nums.size() ; i++)
            dp[i][0]=1;
        for(int i = nums.size()-1 ; i >=0 ; i--)
        {
            for(int tar = 0 ; tar <= target ; tar++)
            {
                bool take = 0;
                if(tar>=nums[i])
                    take = dp[i+1][tar-nums[i]];
                bool nottake = dp[i+1][tar];
                dp[i][tar]=take||nottake;
            }
        }
        return dp[0][target];
    }
};