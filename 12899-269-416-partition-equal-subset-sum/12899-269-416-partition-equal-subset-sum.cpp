class Solution {
public:
    bool canPartition(vector<int>& nums){
        int sum = 0;
        for(int i : nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        int target = sum/2;
        vector<int>curr(target+1,0),next(target+1,0);     
        next[0]=1;
        for(int i = nums.size()-1 ; i >=0 ; i--)
        {
            for(int tar = 0 ; tar <= target ; tar++)
            {
                bool take = 0;
                if(tar>=nums[i])
                    take = next[tar-nums[i]];
                bool nottake = next[tar];
                curr[tar]=take||nottake;
            }
            next = curr;
        }
        return curr[target];
    }
};