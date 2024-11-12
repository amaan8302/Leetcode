class Solution {
public:
    int binarySearch(vector<vector<int>>& items, int tar, int n)
    {
        int low = 0;
        int high = n - 1;
        int result = -1;  
        int ans = 0;
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            // if (items[mid][0] == tar) 
            // {
            //     result = mid;   
            //     low = mid + 1;  
            // } 
            if (items[mid][0] > tar)
                high = mid - 1;
            else
            {
                ans = max(ans,items[mid][1]);
                low = mid + 1;
            }
        }
        // if(result == -1)
        //     return 0;
        // return items[result][1];
        return ans;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        int m = queries.size();
        std::sort(items.begin(),items.end());
        // std::sort(queries.begin(),queries.end());
        vector<int>ans;
        int seen = items[0][1];
        for(int i = 1 ; i < items.size() ; i++)
        {
            seen = max(seen , items[i][1]);
            items[i][1] = seen;
        }
        for(int i = 0 ; i < m ; i++)
            ans.push_back(binarySearch(items,queries[i],items.size()));
        return ans;
    }
};