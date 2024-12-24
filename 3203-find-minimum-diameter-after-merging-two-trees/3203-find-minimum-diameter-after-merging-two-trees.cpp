class Solution {
public:
    pair<int,int> bfs(unordered_map<int,list<int>>adj , int src)
    {
        queue<int>que;
        que.push(src);
        unordered_map<int,bool>visited;
        visited[src]=true;
        int distance = 0;
        int farthestNode = src;
        while(!que.empty())
        {
            int size = que.size();
            while(size--)
            {
                int curr = que.front();
                que.pop();
                farthestNode = curr;
                for(auto &i : adj[curr])
                {
                    if(!visited[i])
                    {
                        visited[i]=true;
                        que.push(i);
                    }
                }
            }
            if(!que.empty())
            {
                distance++;
            }
        }
        return {farthestNode,distance};
    }
    int findDia(unordered_map<int,list<int>>adj)
    {
        auto[farthestNode, dis] = bfs(adj,0);
        auto[otherNode, diameter] = bfs(adj,farthestNode);
        return diameter;
    }
    unordered_map<int,list<int>> buildAdj(vector<vector<int>>& edges1)
    {
        unordered_map<int,list<int>>adj;
        for(int i = 0 ; i < edges1.size() ; i++)
        {
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,list<int>>adj1=buildAdj(edges1);
        unordered_map<int,list<int>>adj2=buildAdj(edges2);
        int d1 = findDia(adj1);
        int d2 = findDia(adj2);
        int combined = (d1+1)/2 + (d2+1)/2 +1;
        return max({d1,d2,combined});
    }
};