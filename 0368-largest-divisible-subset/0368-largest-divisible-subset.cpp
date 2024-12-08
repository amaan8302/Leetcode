class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1);
        vector<int>prev(n+1,-1);
        int l = 0;
        int maxL = 1;
        for(int i = 1 ; i <n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                    if(dp[i]>maxL)
                    {
                        maxL=dp[i];
                        l=i;
                    }
                }
            }
        }
        vector<int>res;
        while(l!=-1)
        {
            res.push_back(nums[l]);
            l = prev[l];
        }
        return res;
    }
};