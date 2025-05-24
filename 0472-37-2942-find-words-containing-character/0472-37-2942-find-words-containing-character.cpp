class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        auto lambda = [x](char ch) {
            return ch == x;
        };
        for (int i = 0; i < words.size(); ++i) {
            if (any_of(words[i].begin(), words[i].end(), lambda)) {
                result.push_back(i);
            }
        }
        return result;
    }
};
