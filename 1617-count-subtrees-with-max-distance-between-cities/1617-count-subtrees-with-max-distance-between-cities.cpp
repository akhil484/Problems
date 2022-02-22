class Solution {
public:
    int caldist(int state, vector<vector<int>>& dist, int n)
    {
        int cntCity=0,cntEdge=0,maxDist=0;
        for(int i=0;i<n;i++)
        {
            if(((state>>i)&1)==0)
                continue;
            cntCity++;
            for(int j=i+1;j<n;j++)
            {
                if(((state>>j)&1)==0)
                    continue;
                cntEdge+=dist[i][j]==1;
                maxDist=max(maxDist,dist[i][j]);
            }
        }
        if(cntEdge!=cntCity-1)
            return 0;
        return maxDist;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int distance = n;
        vector<vector<int>> dist(n,vector<int>(n,distance));
        for(auto e:edges)
        {
            dist[e[0]-1][e[1]-1]=1;
            dist[e[1]-1][e[0]-1]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int> ans(n-1,0);
        for(int state=0;state<(1<<n);state++)
        {
            int d = caldist(state,dist,n);
            if(d>0)
                ans[d-1]+=1;
        }
        return ans;
    }
};