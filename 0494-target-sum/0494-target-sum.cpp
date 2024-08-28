class Solution {
public:
    int solve(vector<int>& nums, int target,int index)
    {
        if(target == 0 && index == nums.size())
            return 1;
        if(index>=nums.size())
            return 0;
        int plus = solve(nums,target-nums[index],index+1);
        int minus = solve(nums,target+nums[index],index+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return solve(nums,target,0);
    }
};