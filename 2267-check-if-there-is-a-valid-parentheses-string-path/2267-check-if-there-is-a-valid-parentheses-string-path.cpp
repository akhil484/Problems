class Solution {
public:
    int solve(vector<vector<char>>& grid, vector<vector<vector<int>>> &dp, int i, int j, int count,int n, int m)
    {
        if(i<0||j<0||i>=n||j>=m)
            return 0;
        count+=(grid[i][j])=='('?1:-1;
        if(count<0||count>(m+n)/2)
            return 0;
        if(i==n-1&&j==m-1&&count==0)
            return 1;
        if(dp[i][j][count]!=-1)
            return dp[i][j][count];
        if(solve(grid,dp,i+1,j,count,n,m))
            return dp[i][j][count] = 1;
        if(solve(grid,dp,i,j+1,count,n,m))
            return dp[i][j][count] = 1;
        return dp[i][j][count]=0;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m+n,-1)));
        int count = 0;
        return solve(grid,dp,0,0,count,n,m)==1?true:false;
    }
};