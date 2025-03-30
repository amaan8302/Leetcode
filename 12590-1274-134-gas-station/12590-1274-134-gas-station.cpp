class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int tg=0,tc=0,n=gas.size();
        for(int i = 0 ; i < n ; i++)
        {
            tg+=gas[i];
            tc+=cost[i];
        }
        if(tc>tg)
            return -1;
        int i = 0,start=0,diff = 0;
        while(i<n)
        {
            diff += (gas[i]-cost[i]);
            if(diff<0)
            {
                start = i+1;
                diff = 0;
            }
            i++;
        }
        return start;
    }
};