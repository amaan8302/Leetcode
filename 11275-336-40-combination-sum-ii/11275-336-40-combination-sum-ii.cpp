class Solution {
public:
    void solve(vector<int> &arr, int target,vector<int>&curr, int index ,vector<vector<int>>&res)
    {
        if(target<0)
            return;
        if(target==0) {res.push_back(curr); return;}
        for(int i = index ; i < arr.size() ; i++)
        {
            if(i>index && arr[i]==arr[i-1])
                continue;
            curr.push_back(arr[i]);
            solve(arr,target-arr[i],curr,i+1,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &arr, int target) {
        std::sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        vector<int>curr;
        solve(arr, target, curr, 0, res);
        return res;
    }
};