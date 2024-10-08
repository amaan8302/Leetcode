class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<int>curr(n+1,0),prev(n+1,0);
        prev[0]=1;
        for (int j = 1; j <= n; j++) 
        {
            if (p[j - 1] == '*') 
                prev[j] = prev[j - 1];
        }
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') 
                    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*') 
                    curr[j] = prev[j] || curr[j - 1];
                else 
                    curr[j] = false;
            }
            prev=curr;
        }
        return prev[n];
    }
};
