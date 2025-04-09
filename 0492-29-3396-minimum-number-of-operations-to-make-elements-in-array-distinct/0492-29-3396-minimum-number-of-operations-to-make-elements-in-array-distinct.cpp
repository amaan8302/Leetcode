class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        int i = n-1;
        while(i>=0)
        {
            if(st.count(nums[i]))
                return ceil((i+1)/3.0);
            st.insert(nums[i]);
            i--;
        }
        return 0;
    }
};