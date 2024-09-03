class Solution {
public:
    int days1(vector<int> &v, int mid)
    {
        int day = 1;
        int load = 0;
        for (int i : v)
        {
            if (load + i <= mid)
                load += i;
            else
            {
                load = i;
                day++;
            }
        }
        return day;
    }
    // int binarySearch(vector<int> &w, int low, int high, int TargetDays)
    // {
    //     if(low<=high)
    //     {
    //         int mid = low + (high - low) / 2;
    //         if (days(w, mid) <= TargetDays)
    //             return binarySearch(w, low, mid - 1, TargetDays);
    //         else
    //             return binarySearch(w, mid + 1, high, TargetDays);
    //     }
    //     return low;
    // }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(days1(weights,mid)<=days)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};