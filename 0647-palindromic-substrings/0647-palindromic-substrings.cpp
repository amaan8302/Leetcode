class Solution {
public:
    int expandAroundCenter(const string &s, int left, int right) 
    {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            ++count;
            --left;
            ++right;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += expandAroundCenter(s, i, i);
            count += expandAroundCenter(s, i, i + 1);
        }
        return /*dp[n][n]=*/count;
    }
};
