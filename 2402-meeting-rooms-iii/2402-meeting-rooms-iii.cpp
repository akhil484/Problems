class Solution {
public:
    int calculate(vector<int> &freetime, int starttime)
    {
        int index=-1;
        int minTime=INT_MAX;
        for(int i=0;i<freetime.size();i++)
        {
            if(freetime[i]<=starttime)
                return i;
            if(freetime[i]<minTime)
            {
                index=i;
                minTime = freetime[i];
            }
        }
        return 0;
    }
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> pq2;
        for(int i=0;i<n;i++)
            pq1.push(i);
        
        for(auto m:meetings)
        {
            while(!pq2.empty()&&pq2.top().first<=m[0])
            {
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            long long duration = m[1]-m[0];
            int room = pq1.empty()?pq2.top().second:pq1.top();
            long long start = pq1.empty()?pq2.top().first:m[0];
            if(pq1.empty())
                pq2.pop();
            else
                pq1.pop();
            rooms[room]++;
            pq2.push({start+duration,room});
        }
        int maxMeetings=rooms[0];
        int room=0;
        for(int i=1;i<n;i++)
        {
            if(rooms[i]>maxMeetings)
            {
                room = i;
                maxMeetings=rooms[i];
            }
        }
        return room;
    }
};