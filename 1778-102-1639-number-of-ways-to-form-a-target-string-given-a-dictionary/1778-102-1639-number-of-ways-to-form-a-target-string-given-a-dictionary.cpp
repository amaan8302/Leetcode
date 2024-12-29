class Solution {
public:
    int m;
    int k;
    const int mod = 1e9+7;
    int solve(vector<vector<long long>>&freq, int i , int j , string &target,vector<vector<int>>&dp)
    {
        if(i==m)
            return 1;
        if(j==k)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int nottaken = solve(freq,i,j+1,target,dp)%mod;
        int take = (freq[target[i]-'a'][j] * solve(freq,i+1,j+1,target,dp))%mod;
        return dp[i][j] = (nottaken+take)%mod;
    }
    int numWays(vector<string>& words, string target) {
        m = target.length();
        k = words[0].length();
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        vector<vector<long long>>freq(26,vector<long long>(k));
        for(int i = 0 ; i < k ; i++)
        {
            for(string &j : words)
            {
                char ch = j[i];
                freq[ch-'a'][i]++;
            }
        }
        return solve(freq,0,0,target,dp);
    }
};