class Solution {
public:

    int thirdLargest(vector<int> &arr) {
        set<int> s(arr.begin(), arr.end());
        priority_queue<int> pq(s.begin(), s.end());
        if (s.size() < 3)
            return pq.top();
        int i = 2;
        while (i--)
            pq.pop();
        return pq.top();
    }
    int thirdMax(vector<int>& nums) {
        return thirdLargest(nums);
    }


};