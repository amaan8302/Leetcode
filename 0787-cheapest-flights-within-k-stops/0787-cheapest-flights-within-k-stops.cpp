class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i = 0 ; i < flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        int stops = 0;
        vector<int>cost(n,INT_MAX);
        queue<pair<int,int>>que;
        que.push({src,0});
        cost[src]=0;
        while(!que.empty() && stops<=k)
        {
            int size = que.size();
            while(size--)
            {
                pair<int,int>top = que.front();
                int u = top.first;
                int d = top.second;
                que.pop();
                for(pair<int,int>&i:adj[u])
                {
                    int v = i.first;
                    int cst = i.second;
                    if(cost[v]>d+cst)
                    {
                        cost[v] = d+cst;
                        que.push({v,d+cst});
                    }
                }    
            }
            stops++;
        }
        if(cost[dst]==INT_MAX)
            return -1;
        return cost[dst];
    }
};