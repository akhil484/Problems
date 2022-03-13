class Solution {
public:
    long m =10000000000;
    void Dijkstra(int src, vector<pair<long,long>> adj[], vector<long> &dist)
    {
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> p;
        dist[src]=0;
        p.push({src,0});
        while(!p.empty())
        {
            int node = p.top().first;
            int d = p.top().second;
            p.pop();
            if (dist[node] < d) continue;
            for(auto it:adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if(dist[node]+wt<dist[v])
                {
                    dist[v] = dist[node]+wt;
                    p.push({v,dist[v]});
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<pair<long,long>> adj[n];
        vector<pair<long,long>> revadj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            revadj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<long>fromSrc1To(n, m), fromSrc2To(n, m), fromDestTo(n, m);
        Dijkstra(src1, adj, fromSrc1To);
		Dijkstra(src2, adj, fromSrc2To);
		Dijkstra(dest, revadj, fromDestTo);
        if(fromSrc1To[dest]==m||fromSrc2To[dest]==m)
            return -1;
        long ans=m;
        for(int i=0;i<n;i++)
        {
            ans = min(ans, fromSrc1To[i] + fromSrc2To[i] + fromDestTo[i]);
        }
        return ans;
    }
};