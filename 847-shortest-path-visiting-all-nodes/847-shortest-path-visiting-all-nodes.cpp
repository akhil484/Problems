class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int targetmask = (1<<n)-1;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) q.push({i, 1 << i});

        vector<vector<int>> vis(n,vector<int>(1<<n,0));
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int node=q.front().first;
                int mask=q.front().second;
                q.pop();
                if(mask==targetmask)
                    return level;
                if(vis[node][mask])
                    continue;
                vis[node][mask] = true;
                for(auto adj:graph[node])
                {
                    int nextmask = mask|(1<<adj);
                    if(!vis[adj][nextmask])
                    {
                        q.push({adj,nextmask});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};