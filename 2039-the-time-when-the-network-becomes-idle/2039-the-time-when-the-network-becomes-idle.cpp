class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector <int> time(n, -1);
        queue<int> q;
        q.push(0);
        time[0]=0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int x:graph[node])
            {
                if(time[x]==-1)
                {
                    time[x] = time[node]+1;
                    q.push(x);
                }
            }
        }
        int res=0;
        for(int i=1;i<n;i++)
        {
            int extramsg = (time[i]*2-1)/patience[i];
            int lastmsg = extramsg*patience[i];
            int t = lastmsg+time[i]*2;
            res = max(res,t);
        }
        return res+1;
    }
};