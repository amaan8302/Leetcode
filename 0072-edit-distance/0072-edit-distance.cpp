class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+2,vector<int>(word2.length()+2,0));
        for(int i = 0 ; i < word1.length();i++)
            dp[i][word2.length()]=word1.length()-i;
        for(int i = 0 ; i < word2.length();i++)
            dp[word1.length()][i]=word2.length()-i;
        for(int i = word1.length()-1; i>=0 ;i--)
        {
            for(int j = word2.length()-1 ; j>=0 ; j--)
            {
                if(word1[i]==word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else
                {
                    int insertion,deletion,replace;
                    //insert
                    insertion = 1 + dp[i][j+1];
                    //deletion
                    deletion = 1 + dp[i+1][j];
                    //replacement
                    replace = 1 + dp[i+1][j+1];
                    dp[i][j] = min(insertion,min(deletion, replace));
                }
            }
        }
        return dp[0][0];
        // return solve(word1,word2,0,0,dp);
    }
};