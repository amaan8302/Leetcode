class Solution {
public:
    int solve(int i, int j , vector<int>& g, vector<int>& s)
    {
        if(i>=g.size() || j>=s.size())
            return 0;
        int count;
        if(g[i]<=s[j])
            count = 1 + solve(i+1,j+1,g,s);
        if(g[i]>s[j])
            count = solve(i, j + 1, g, s);
        return count;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        return solve(0,0,g,s);
    }
};