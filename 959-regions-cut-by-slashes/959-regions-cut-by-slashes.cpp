class Solution {
public:
    void dfs(vector<vector<int>> &graph, int i, int j)
    {
        if(i>=graph.size()||i<0||j<0||j>=graph[0].size()||graph[i][j]==1)
            return;
        graph[i][j]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int z=0;z<4;z++)
        {
            dfs(graph,i+dx[z],j+dy[z]);
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].length();j++)
            {
                if(grid[i][j]=='/')
                {
                    graph[i*3+2][j*3]=1;
                    graph[i*3+1][j*3+1]=1;
                    graph[i*3][j*3+2]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    graph[i*3][j*3]=1;
                    graph[i*3+1][j*3+1]=1;
                    graph[i*3+2][j*3+2]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[0].size();j++)
            {
                if(graph[i][j]==0)
                {
                    dfs(graph,i,j);
                    c++;
                }
            }
        }
         return c;   
        }
        
};