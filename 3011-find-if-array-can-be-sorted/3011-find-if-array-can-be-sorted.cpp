class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
    
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            m[nums[i]] = countSetBits(nums[i]);
        
        for (int i = 0; i < n; i++) {
            bool swapp = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (m[nums[j]] == m[nums[j + 1]]) {    
                        swap(nums[j], nums[j + 1]);
                        swapp = true;
                    } else {
                        return false;
                    }
                }
            }
            if (!swapp) break;
        }
        return true;
    }
};
