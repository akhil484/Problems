class Solution {
public:
    long long dp[51][101][51];
    const int MOD = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
     //dp[i][j][k] is ways to create array of length i with max element j and cost k;
        for(int j=1;j<=m;j++)
        {
            dp[1][j][1] =1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int z=1;z<=k;z++)
                {
                    long long s = 0;
                    s = s+(j*dp[i-1][j][z])%MOD;
                    for(int x=1;x<j;x++)
                        s=(s+dp[i-1][x][z-1])%MOD;
                    dp[i][j][z] = dp[i][j][z]+s;
                }
            }
        }
        long long ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + dp[n][j][k]) % MOD;
        }
        
        return int(ans);
    }
};