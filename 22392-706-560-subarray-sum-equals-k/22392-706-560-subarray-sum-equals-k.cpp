class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int res = 0;
        int sum = 0;
        mp.insert({0,1});
        for(int i = 0 ; i < arr.size() ; i++)
        {
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end())
                res = res + mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};