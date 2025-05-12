class Solution {
public:
    typedef pair<long long,int> p;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(),meetings.end());
        priority_queue<p,vector<p>,greater<p>>usedRoom;
        priority_queue<int,vector<int>,greater<int>>availableRooms;
        vector<int>roomsUsedCount(n,0);
        for (int i = 0; i < n; ++i) 
            availableRooms.push(i);
        for(vector<int>&meet : meetings)
        {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            while(!usedRoom.empty() && usedRoom.top().first <= start)
            {
                int room = usedRoom.top().second;
                usedRoom.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty())
            {
                int room = availableRooms.top();
                availableRooms.pop();
                usedRoom.push({(long long)start + duration, room});
                roomsUsedCount[room]++;
            }
            else {
                auto [endTime, room] = usedRoom.top();
                usedRoom.pop();
                usedRoom.push({endTime + duration, room});
                roomsUsedCount[room]++;
            }
        }
        int res = 0;
        for(int i = 1 ; i < n ; i++)
        {
            if(roomsUsedCount[i] > roomsUsedCount[res])
                res = i;
        }
        return res;
    }
};