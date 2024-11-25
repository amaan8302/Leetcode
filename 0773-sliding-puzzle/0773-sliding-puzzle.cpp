class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start;
        
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                start += to_string(board[i][j]);
        
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == target) return steps;
                
                int zero = curr.find('0');
                
                for (int next : moves[zero]) {
                    string temp = curr;
                    swap(temp[zero], temp[next]);
                    
                    if (visited.count(temp) == 0) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};