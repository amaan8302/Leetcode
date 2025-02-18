class Solution {
public:
    typedef pair<double, pair<int, int>> P;
    double solve(int a, int b)
    {
        return sqrt(a*a + b*b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>>ans(k , vector<int>(2,0));
        for(int i = 0 ; i < points.size() ; i++)
        {
            double a = solve(points[i][0] , points[i][1]);
            int b = points[i][0];
            int c = points[i][1];
            pq.push({a, {b, c}});
        }
        for(int i = 0 ; i < k ; i++)
        {
            ans[i][0] = pq.top().second.first;
            ans[i][1] = pq.top().second.second;
            pq.pop();
        }
        return ans;
    }
};