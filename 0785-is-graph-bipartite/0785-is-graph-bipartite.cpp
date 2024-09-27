class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>v(n,-1);
        for(int i = 0 ; i < n ; ++i)
        {
            if(v[i]==-1)
            {
                queue<int>q;
                q.push(i);
                v[i]=0;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(int n : graph[node])
                    {
                        if(v[n]==-1)
                        {
                            v[n]=1-v[node];
                            q.push(n);
                        }
                        else if(v[n]==v[node])
                            return false;
                    }            
                }
            }
        }
        return true;
    }
};