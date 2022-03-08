class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color)
    {
        if(color[node]==-1)
            color[node]=1;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!dfs(it,graph,color))
                    return false;
            }
            else
            {
                if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    
    bool check(vector<vector<int>> &graph, int n)
    {
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1){
            if(!dfs(i,graph,color))
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<int> vis(n+1,0);
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        return check(graph,n);
        
    }
};