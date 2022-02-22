class Solution {
public:
    int dfs(vector<vector<int>>& dist, int state, int i, int &n, int &res)
    {
        // int cntCity=0,cntEdge=0,maxDist=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(((state>>i)&1)==0)
        //         continue;
        //     cntCity++;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(((state>>j)&1)==0)
        //             continue;
        //         cntEdge+=dist[i][j]==1;
        //         maxDist=max(maxDist,dist[i][j]);
        //     }
        // }
        // if(cntEdge!=cntCity-1)
        //     return 0;
        // return maxDist;
        
        int dia = 0, max_dia = 0;
    ++n;
    
    for (auto j : dist[i]){
        if (state & (1 << j)) {
            int dia = 1 + dfs(dist, state ^ (1 << j), j, n, res);
            res = max(res, dia + max_dia);
            max_dia = max(max_dia, dia);
        }
    }
    return max_dia;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int distance = n;
        vector<vector<int>> graph(n);
        for(auto e:edges)
        {
            graph[e[0]-1].push_back(e[1]-1);
            graph[e[1]-1].push_back(e[0]-1);
        }
        // for(int k=0;k<n;k++)
        // {
        //     for(int i=0;i<n;i++)
        //     {
        //         for(int j=0;j<n;j++)
        //         {
        //             dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        //         }
        //     }
        // }
        vector<int> ans(n-1,0);
        for(int state=0;state<(1<<n);state++)
        {
            for(int i=0;i<n;i++)
            {
                if(state& (1 << i)){
                    
                int nodes=0,dia=0;
                dfs(graph,state^(1<<i),i,nodes,dia);
                if(dia>0&&nodes == bitset<16>(state).count())
                    ans[dia-1]+=1;
                break;
            }
            }
        }
        return ans;
    }
};