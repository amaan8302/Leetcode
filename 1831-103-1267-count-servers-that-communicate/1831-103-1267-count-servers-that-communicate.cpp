class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>col(n,0);
        vector<int>row(m,0);
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j]!=0)
                {
                    col[j]++;
                    row[i]++;
                }
            }
        }
        int res = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j]!=0 && (col[j]>1 || row[i]>1))
                    res++;
            }
        }
        return res;
    }
};