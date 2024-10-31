class Solution {
public:
    int minimumMountainRemovals(vector<int>& heights) {
        int size = heights.size();
        vector<int> incSeq(size, 1), decSeq(size, 1);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (heights[i] > heights[j]) {
                    incSeq[i] = max(incSeq[i], incSeq[j] + 1);
                }
            }
        }

        for (int i = size - 1; i >= 0; --i) {
            for (int j = size - 1; j > i; --j) {
                if (heights[i] > heights[j]) {
                    decSeq[i] = max(decSeq[i], decSeq[j] + 1);
                }
            }
        }

        int maxMountain = 0;
        for (int i = 1; i < size - 1; ++i) {
            if (incSeq[i] > 1 && decSeq[i] > 1) {
                maxMountain = max(maxMountain, incSeq[i] + decSeq[i] - 1);
            }
        }

        return size - maxMountain;
    }
};
