class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        // for(auto &a: prices)
        // {
        //     dp[a[0]][a[1]] = a[2];
        //     for(int i=1;i<=m;i++)
        //     {
        //         for(int j=1;j<=n;j++)
        //         {
        //             for(int k=1;k<=i/2;k++)
        //             {
        //                 dp[i][j] = max(dp[i][j],dp[k][j]+dp[i-k][j]);
        //             }
        //             for(int k=1;k<=j/2;k++)
        //             {
        //                 dp[i][j] = max(dp[i][j],dp[i][k]+dp[i][j-k]);
        //             }
        //         }
        //     }
        // }
        // return dp[m][n];
        
        long long dp[201][201] = {};
    for (auto &p : prices)
        dp[p[0]][p[1]] = p[2];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            for (int h = 1; h <= i / 2; ++h)
                dp[i][j] = max(dp[i][j], dp[h][j] + dp[i - h][j]);
            for (int v = 1; v <= j / 2; ++v)
                dp[i][j] = max(dp[i][j], dp[i][v] + dp[i][j - v]);
        }
    return dp[m][n];
    }
};