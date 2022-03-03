class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int row, int col, int r, int c, vector<vector<int>>& dp)
    {
        if(dp[r][c]>0)
            return dp[r][c];
        int res=1;
        if(r+1<row&&matrix[r+1][c]>matrix[r][c])
            res=max(res,1+dfs(matrix,row,col,r+1,c,dp));
        if(r-1>=0&&matrix[r-1][c]>matrix[r][c])
            res=max(res,1+dfs(matrix,row,col,r-1,c,dp));
        if(c+1<col&&matrix[r][c+1]>matrix[r][c])
            res=max(res,1+dfs(matrix,row,col,r,c+1,dp));
        if(c-1>=0&&matrix[r][c-1]>matrix[r][c])
            res=max(res,1+dfs(matrix,row,col,r,c-1,dp));
            
        return dp[r][c]=res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res=0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                res=max(res,dfs(matrix,row,col,i,j,dp));
            }
        }
        return res;
    }
};