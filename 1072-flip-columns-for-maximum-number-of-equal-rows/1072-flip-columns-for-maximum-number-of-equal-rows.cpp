class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>m;
        for(auto &i : matrix)
        {
            string n = "";
            int first = i[0];
            for(int j = 0 ; j < matrix[0].size() ; j++)
                n +=(i[j]==first)?"y":"n";
            m[n]++;
        }
        int maxRows = 0;
        for(auto &it : m)
            maxRows = max(maxRows,it.second);
        return maxRows;
    }
};