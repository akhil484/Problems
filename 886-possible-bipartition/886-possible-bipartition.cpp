class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<int> vis(n+1,0);
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> q;
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                color[i]=0;
                q.push(i);
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    if(vis[u]==1)
                        continue;
                    vis[u]=1;
                    for(int v:graph[u])
                    {
                        if(color[v]==color[u])
                            return false;
                        if(color[u]==0)
                            color[v]=1;
                        else
                            color[v]=0;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};