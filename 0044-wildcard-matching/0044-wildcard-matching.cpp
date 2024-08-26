class Solution {
public:
    bool solve(string &s, string &p , int i , int j,vector<vector<int>>&dp)
    {
        if(i<0 && j<0) //dono strings poori consume ho gai he, return true
            return 1;
        if(i>=0 && j<0)//str not consumed but p is consumed, invalid
            return 0;
        if(i<0 && j>=0)
        {
            for(int i = 0 ; i <= j ; i++)
            {
                if(p[i]!='*')
                    return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans = 0;
        if(s[i]==p[j]||p[j]=='?')
            ans= solve(s,p,i-1,j-1,dp);
        else if(p[j]=='*')
            ans = (solve(s,p,i-1,j,dp) or solve(s,p,i,j-1,dp));
        else
            return 0;
        return dp[i][j]=ans;
            
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
    }
};