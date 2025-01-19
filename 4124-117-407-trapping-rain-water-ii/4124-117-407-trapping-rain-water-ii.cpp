class Solution {
public: 
    vector<vector<int>>directions = {{0,-1},{0,1},{-1,0},{1,0}}; 
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int row = 0 ; row < m ; row++)
        {
            for(int col : {0,n-1})
            {
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=1;
            }
        }
        for(int col = 0 ; col < n ; col++)
        {
            for(int row : {0,m-1})
            {
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=1;
            }
        }
        int ans = 0;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> top = pq.top();
            pq.pop();
            int height = top.first;
            int i = top.second.first;
            int j = top.second.second;
            for(vector<int>&dir : directions)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(ni>=0 && ni<m && nj>=0 && nj<n&&!visited[ni][nj])
                {
                    ans+=max(height-heightMap[ni][nj],0);
                    pq.push({max(height,heightMap[ni][nj]), {ni,nj}});
                    visited[ni][nj]=1;
                }
            }
        }
        return ans;
    }
};