class Solution {
public:
    bool ans(int n, const vector<int>& quantities, int a) {
        for (int quantity : quantities) {
            int storesNeeded = (quantity + a - 1) / a;
            n -= storesNeeded;
            if (n < 0) return true;
        }
        return false;
    }

    int solve(int n, const vector<int>& quantities, int last) {
        int low = 1, high = last, res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ans(n, quantities, mid)) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int last = *max_element(quantities.begin(), quantities.end());
        return solve(n, quantities, last);
    }
};
