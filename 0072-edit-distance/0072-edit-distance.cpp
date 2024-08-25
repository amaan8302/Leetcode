class Solution {
public:
    int solve(string &a, string &b , int i , int j,vector<vector<int>>&dp)
    {
       if(i==a.length())
           return b.length()-j;
        if(j==b.length())
            return a.length()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        if(a[i]==b[j])
            ans = solve(a,b,i+1,j+1,dp);
        else
        {
            int insertion,deletion,replace;
            //insert
            insertion = 1 + solve(a,b,i,j+1,dp);
            //deletion
            deletion = 1 + solve(a,b,i+1,j,dp);
            //replacement
            replace = 1 + solve(a,b,i+1,j+1,dp);
            ans = min(insertion,min(deletion, replace));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        
            vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
            return solve(word1,word2,0,0,dp);
    }
};