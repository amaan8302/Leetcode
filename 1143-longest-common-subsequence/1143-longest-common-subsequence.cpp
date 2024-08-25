class Solution {
public:   
     int longestCommonSubsequence(string a, string b) {
        int n1=a.size();
        int n2=b.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        // return solve(text1,text2,0,0,dp);
        for(int i = n1-1 ; i >=0 ; i--)
        {
            for(int j = n2-1 ; j>= 0 ;j--)
            {
                // int ans = 0;
                if(a[i]==b[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};