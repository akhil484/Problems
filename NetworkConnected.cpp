class Solution {
public:
    void dfs(vector<vector<int>>& graph , vector<bool>& visited , int start)
    {
        visited[start]=true;
        for(auto it:graph[start])
        {
            if(!visited[it])
                dfs(graph,visited,it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)      //(nodes=edges-1 for all of its nodes to be connected)
            return -1;
        vector<vector<int>> graph(n);
        for(auto au:connections)
        {
            graph[au[0]].push_back(au[1]);
            graph[au[1]].push_back(au[0]);
        }
        vector<bool> visited(n,false);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                c++;
                dfs(graph,visited,i);
            }
        }
        return c-1;
    }
};
