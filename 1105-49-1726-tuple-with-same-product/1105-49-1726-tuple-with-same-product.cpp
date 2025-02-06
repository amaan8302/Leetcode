class Solution {
public:
    int tupleSameProduct(vector<int>& nums)
    {
        unordered_map<int, vector<pair<int, int>>> productMap;
        int count = 0;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j) 
            {
                int product = nums[i] * nums[j];
                if (productMap.count(product)) 
                    count += productMap[product].size();  
                productMap[product].emplace_back(nums[i], nums[j]);
            }
        }
        return count * 8;  
    }
};