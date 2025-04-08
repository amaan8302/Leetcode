class TrieNode {
public:
    TrieNode* children[26] = {};
    vector<string> suggestions;
};
class Solution {
public:
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            if (node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();

        for (const string& product : products)
            insert(root, product);

        vector<vector<string>> result;
        TrieNode* node = root;
        for (char ch : searchWord) {
            int idx = ch - 'a';
            if (node)
                node = node->children[idx];
            if (node)
                result.push_back(node->suggestions);
            else
                result.push_back({});
        }
        return result;
    }
};