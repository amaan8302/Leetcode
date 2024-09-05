class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int m = rolls.size();
        vector<int> result;
        int sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        int target = mean * (m + n) - sum;
        if(target > 6 * n || target < n)
            return result;

        int avg = target / n, rem = target % n;
        result.resize(n, avg);
        for(int i = 0; i < rem; ++i)
            result[i]++;
        
        return result;
    }
};
