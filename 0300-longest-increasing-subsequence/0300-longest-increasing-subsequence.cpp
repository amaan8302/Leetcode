class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int>f(n+1,0);
        vector<int>s(n+1,0);
        for(int curr = n-1 ; curr>=0 ; curr--)
        {
            for(int prev = curr-1 ; prev>=-1;prev--)
            {
                int incl = 0;
                if(prev==-1 || a[curr]>a[prev])
                    incl = 1 + s[curr+1];
                int excl = s[prev+1];
                f[prev+1]=max(incl,excl);
            }
            s=f;
        }
        return s[0];
    }
};