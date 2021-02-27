class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;

//         for(int i=0;i<n;i++)
//         {
//             adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
//         }
        for(auto f : flights)
            adj[f[0]].push_back({f[1],f[2]});
        q.push({0,src,K+1});
        while(q.size()!=0)
        {
            vector<int> t=q.top();
            q.pop();
            int d=t[1];
            int f=t[0];
            int e=t[2];
            if(dst==d)
                return f;
            if(e>0)
            {
                for(auto v : adj[d])
                    q.push({f+v.second,v.first,e-1});
            }
        }
        return -1;
    }
};
