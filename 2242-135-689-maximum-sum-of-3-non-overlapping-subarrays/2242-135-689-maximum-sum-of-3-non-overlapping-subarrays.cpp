class Solution {
public:
    int sum (vector<int>& nums,int start, int k)
    {
        int sum = 0;
        if(k+start <= nums.size())
        {
            for(int i = start ; i < k+start; i++)
                sum +=nums[i];   
        }
        return sum;
    }
    int amaan(vector<int>&nums,int cnt,int i, int k,vector<vector<int>>&dp)
    {
        if(cnt==0)
            return 0;
        if(i>=nums.size())
            return INT_MIN;
        if(dp[cnt][i]!=-1)
            return dp[cnt][i];
        int take = nums[i] + amaan(nums,cnt-1,i+k,k,dp);
        int nottake = amaan(nums,cnt,i+1,k,dp);
        return dp[cnt][i] = max(take,nottake);
    }
    void solve(vector<int>& nums, int k, int i, int cnt,vector<int>&res,vector<vector<int>>&dp)
    {
        if(cnt==0)
            return;
        if(i>=nums.size())
            return;
        int take = nums[i] + amaan(nums,cnt-1,i+k,k,dp);
        int nottake = amaan(nums,cnt,i+1,k,dp);
        if(take>=nottake)
        {
            res.push_back(i);
            solve(nums,k,i+k,cnt-1,res,dp);            
        }
        else
            solve(nums,k,i+1,cnt,res,dp);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>subarray;
        int windowSum = 0;
        int i = 0, j=0;
        int n = nums.size();
        vector<vector<int>>dp(4,vector<int>(n+1,-1));
        while(j<nums.size())
        {
            windowSum+=nums[j];
            if(j-i+1==k)
            {
                subarray.push_back(windowSum);
                windowSum-=nums[i];
                i++;
            }
            j++;
        }
        vector<int>res;
        solve(subarray,k,0,3,res,dp);
        return res;
    }
};