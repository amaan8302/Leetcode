class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int>vec(n);
        vec[n-1]=n-1;
        for(int i = n-2 ; i >= 0 ; i--)
        {
            int rightMax = vec[i+1];
            int ele = s[rightMax];
            vec[i]=(s[i]>ele)?i:rightMax;
        }
        for(int i = 0 ; i < n ; i++)
        {
            int a = vec[i];
            int ele = s[a];
            if(s[i]<ele)
            {
                swap(s[i],s[a]);
                return stoi(s);
            }
        }
        return num;
    }
};