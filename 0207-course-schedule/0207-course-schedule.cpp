class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>indegree(n);
        for(auto i : adj)
        {
            for(auto j : i.second)
                indegree[j]++;
        }
        queue<int>q;
        int count=0;
        for(int i = 0 ; i < n ; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;
            for(auto i : adj[front])
            {
                indegree[i]--;
                if(indegree[i]==0)  
                    q.push(i);
            }
        }
        if(count == n)
            return 1;
        else
            return 0;
    }
};