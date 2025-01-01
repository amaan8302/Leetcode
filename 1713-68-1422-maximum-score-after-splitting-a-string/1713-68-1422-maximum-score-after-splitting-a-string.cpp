class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        if (n < 2) return 0;
        int totalOnes = 0;
        for (char c : s)
            if (c == '1') totalOnes++;
        int leftZeros = 0;
        int rightOnes = totalOnes;
        int maxScore = 0;
        for (int i = 0; i < n - 1; i++)
         {
            if (s[i] == '0')
                leftZeros++;
            else
                rightOnes--;
            int currentScore = leftZeros + rightOnes;
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};