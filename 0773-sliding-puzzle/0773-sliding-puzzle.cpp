class Solution {
public:
    void solve(vector<vector<int>>& board, string &res)
    {
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0 ; j < 3 ;j++)
                res += to_string(board[i][j]);
        }
    }
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        unordered_map<int,list<int>>mp;
        queue<string>que;
        string res="";
        string target = "123450";
        solve(board , res);
        que.push(res);
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={2,4};
        unordered_set<string>visited;
        visited.insert(res);
        int lvl = 0;
        while(!que.empty())
        {
            int n = que.size();
            while(n--)
            {
                string top = que.front();
                que.pop();
                if(top==target)
                    return lvl;
                int idx = top.find('0');
                for(auto &i : mp[idx])
                {
                    string newState = top;
                    swap(newState[idx],newState[i]);
                    if(visited.find(newState)==visited.end())
                    {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};