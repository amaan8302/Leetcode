class Solution {
public:
    int solve(int n, vector<int>& cuts, int left, int right,vector<vector<int>>&dp)
    {
        if(right-left<2)
            return 0;
        if(dp[left][right]!=-1)
            return dp[left][right];
        int result = INT_MAX, cost;
        for(int i = left+1 ; i < right ; i++)
        {
            cost = cuts[right]-cuts[left] + solve(n,cuts,left,i,dp) + solve(n,cuts,i,right,dp);
            result = min(result,cost);
        }
        return dp[left][right]=result;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        
        std::sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solve(n,cuts,0,m-1,dp);
    }
};