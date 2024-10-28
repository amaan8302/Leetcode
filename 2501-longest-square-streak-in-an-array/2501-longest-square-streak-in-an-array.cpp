class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        int maxi = 0;
        for(int &i : nums)
        {
            int root = (int)sqrt(i);
            if(root*root == i && m.find(root)!=m.end()){
                m[i] = m[root]+1;
            }
            else
                m[i]=1;
            maxi = max(maxi,m[i]);
        }
        if(maxi<2)
            return -1;
        return maxi;
    }
};