class Solution {
public:
    int solve(int i , int n , vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i>n)
            return 0;
        if(dp[i][n]!=-1)
            return dp[i][n];
        int maxi = INT_MIN;
        for(int m = i ; m<=n ; m++)
        {
            int cost = nums[i-1]*nums[m]*nums[n+1] + solve(i,m-1,nums,dp)+solve(m+1,n,nums,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][n]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(1,n,nums,dp);
    }
};