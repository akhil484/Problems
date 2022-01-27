class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int h, int x, int y)
    {
        if(x<0||y<0||x>=heights.size()||y>=heights[0].size()||visited[x][y]||heights[x][y]<h)
            return;
        visited[x][y]=1;
        int dx[]={0,1,-1,0};
        int dy[]={-1,0,0,1};
        for(int i=0;i<4;i++)
        {
            dfs(heights,visited,heights[x][y],x+dx[i],y+dy[i]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> pacific(row,vector<int>(col,0));
        vector<vector<int>> atlantic(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            dfs(heights,pacific,INT_MIN,i,0);
            dfs(heights,atlantic,INT_MIN,i,col-1);
        }
        for(int i=0;i<col;i++)
        {
            dfs(heights,pacific,INT_MIN,0,i);
            dfs(heights,atlantic,INT_MIN,row-1,i);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(pacific[i][j]&&atlantic[i][j])
                {
                    res.push_back({i,j});
                }
                
            }
        }
        return res;
    }
};