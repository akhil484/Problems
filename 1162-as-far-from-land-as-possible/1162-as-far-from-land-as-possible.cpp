class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        if(q.size()==row*col)
            return -1;
        int dist=0;
        int dx[] = {0,1,0,-1};
        int dy[] = {-1,0,1,0};
        while(!q.empty())
        {
            int size = q.size();
            dist++;
            while(size--)
            {
                auto [x,y] = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0&&ny>=0&&nx<row&&ny<col&&grid[nx][ny]==0)
                    {
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
        }
        return dist-1;
    }
};