class Solution {
public:   
    int longestCommonSubsequence(string a, string b)
    {
        int n1=a.size();
        int n2=b.size();
        vector<int>curr(n2+1,0);
        vector<int>next(n2+1,0);
        for(int i = n1-1 ; i >=0 ; i--)
        {
            for(int j = n2-1 ; j>= 0 ;j--)
            {
                if(a[i]==b[j])
                    curr[j] = 1 + next[j+1];
                else
                    curr[j] = max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return next[0];
    }
};