class Solution {
public:
    int bfs(int st, unordered_map<int,list<int>>&adj,vector<bool>&visited)
    {
        queue<pair<int,int>>q;
        q.push({st,0});
        int maxDis=0;
        while(!q.empty())
        {
            auto [currNode,dis]=q.front();
            q.pop();
            for(auto &i : adj[currNode])
            {
                if(!visited[i])
                {
                    visited[i]=1;
                    q.push({i,dis+1});
                    maxDis = max(maxDis,dis+1);
                }
            }
        }
        return maxDis;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int,list<int>>adj;
        for(int i = 0 ; i < n ; i++)
        {
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }
        int maxLen = 0;
        int happy = 0;
        vector<bool>visited(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                unordered_map<int,int>mp;
                int currNode = i;
                int currNodeCnt = 0;
                while(!visited[currNode])
                {
                    visited[currNode]=1;
                    mp[currNode] = currNodeCnt;
                    int nxtNode = favorite[currNode];
                    currNodeCnt+=1;
                    if(mp.count(nxtNode))
                    {
                        int cycleLen = currNodeCnt - mp[nxtNode];
                        maxLen = max(maxLen,cycleLen);
                        if(cycleLen == 2)
                        {
                            vector<bool>visitedNode(n,false);
                            visitedNode[currNode]=1;
                            visitedNode[nxtNode]=1;
                            happy += 2 + bfs(currNode,adj,visitedNode)+bfs(nxtNode,adj,visitedNode);
                        }
                        break;
                    }
                    currNode = nxtNode;
                }
            }
        }
        return max(happy,maxLen);
    }
};