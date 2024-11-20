class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        unordered_map<char, int> m;
        m['a'] = 0;
        m['b'] = 0;
        m['c'] = 0;

        // Count the total occurrences of 'a', 'b', 'c' in the string
        for (char c : s)
            m[c]++;
        
        // If any character count is less than k, it's impossible
        if (m['a'] < k || m['b'] < k || m['c'] < k)
            return -1;

        int n = s.length();
        int i = 0, maxLen = 0;

        // Sliding window to find the longest valid substring
        for (int j = 0; j < n; j++) {
            m[s[j]]--;
            
            while (m['a'] < k || m['b'] < k || m['c'] < k) {
                m[s[i]]++;
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
        }

        return n - maxLen;
    }
};
