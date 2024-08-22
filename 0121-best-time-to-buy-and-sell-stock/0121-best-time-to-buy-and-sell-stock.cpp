class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int h = 0;
    int l = INT_MAX;

    for (int i : prices) {
        l = min(l, i);
        h = max(h, i - l); 
    }

    return h;
    }
};