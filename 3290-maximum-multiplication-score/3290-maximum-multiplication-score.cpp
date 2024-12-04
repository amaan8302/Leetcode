class Solution {
public:
    long long solve(vector<int>& a, vector<int>& b, int ia, int ib, int n, vector<vector<long long int>>&dp)
    {
        if(ia >= 4)
            return 0;
        if(ib >= n)
            return LLONG_MIN/2;
        
        if(dp[ia][ib] != -1)
            return dp[ia][ib];
        
        long long int take = (long long)b[ib] * (long long)a[ia] + solve(a,b,ia+1,ib+1,n,dp);
        long long int nottake = solve(a,b,ia,ib+1,n,dp);
        
        return dp[ia][ib] = max(take, nottake);   
    }
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long int>>dp(5,vector<long long int>(b.size()+1,-1));
        return solve(a,b,0,0,b.size(),dp);
    }
};