class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxI = values[0];
        for (int j = 1; j < values.size(); ++j)
        {
            maxScore = std::max(maxScore, maxI + values[j] - j);
            maxI = std::max(maxI, values[j] + j);
        }
        return maxScore;
    }
};