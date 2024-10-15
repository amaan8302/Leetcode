class Solution {
public:
    typedef pair<int,int>p;
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        if(n==1||n==0)
            return 0;
        queue<p>que;
        set<p>vis;
        for(int i = 0 ; i < n ; i++)
        {
            int maskVal = (1<<i);
            que.push({i,maskVal});
            vis.insert({i,maskVal});
        }
        int allVisited = (1<<n)-1;
        int path=0;
        while(!que.empty())
        {
            int size = que.size();
            path++;
            while(size--)
            {
                p curr = que.front();
                que.pop();
                int currNode = curr.first;
                int currMask = curr.second;
                for(int &adj : graph[currNode])
                {
                    int nextMask = currMask | (1<<adj);
                    if(nextMask==allVisited)
                        return path;
                    if(vis.find({adj,nextMask})==vis.end())
                    {   
                        vis.insert({adj,nextMask});
                        que.push({adj,nextMask});
                    }
                }
            }
        }
        return -1;
    }
};