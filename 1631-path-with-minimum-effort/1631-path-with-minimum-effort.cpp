class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        priority_queue<P, vector<P>,greater<P>>pq;
        res[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int diff = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();
            int x = cord.first;
            int y = cord.second;
            if(x== m-1 && y==n-1)
                return diff;
            for(auto &d : dirs)
            {
                int nx = x + d[0];
                int ny = y + d[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    int absDiff = abs(heights[x][y] - heights[nx][ny]);
                    int maxDiff = max(diff, absDiff);
                    if(res[nx][ny]>maxDiff)
                    {    
                        res[nx][ny]=maxDiff;
                        pq.push({maxDiff,{nx,ny}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};