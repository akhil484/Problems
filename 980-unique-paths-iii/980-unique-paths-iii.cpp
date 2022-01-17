class Solution {
public:
    
    void dfs(vector<vector<int>> &grid, int empty, int x, int y, int &path,vector<vector<int>> &vis, int total_vis)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]==-1)
            return;
        if(grid[x][y]==2)
        {
            
            if(total_vis==empty)
            {
                cout<<"Reach";
                path++;
            }
                
            return;
        }
        int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
        if((grid[x][y]==0)&&vis[x][y]==0)
        {
            
            vis[x][y]=1;
            for(int i=0;i<4;i++)
            {
                dfs(grid,empty,x+dx[i],y+dy[i],path,vis,total_vis+1);

            }
            vis[x][y]=0;
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int empty = 0,startx=-1,endx=-1;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                    empty++;
                else if(grid[i][j]==1)
                {
                    startx=i;
                    endx=j;
                }
                
            }
        }
        int path = 0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++)
            {
                dfs(grid,empty,startx+dx[i],endx+dy[i],path,vis,0);

            }
        
        return path;
    }
};