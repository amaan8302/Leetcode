class Solution {
public:
    bool isValid(long long time, vector<int>& ranks, int cars)
    {
        long long sum = 0;
        for (int i : ranks)
        {
            if (time < i) continue;
            sum += sqrt((double)time / i);
        }
        return sum >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = (long long)(*max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long res = -1;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(isValid(mid, ranks,cars))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};