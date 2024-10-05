class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        for (char c : s1)
            count[c - 'a']++;
        int left = 0, right = 0, size = s1.size(), remaining = size;
        while (right < s2.size()) {
            if (count[s2[right++] - 'a']-- > 0)
                remaining--;
            if (remaining == 0)
                return true;
            if (right - left == size && count[s2[left++] - 'a']++ >= 0)
                remaining++;
        }
        return false;
    }
};