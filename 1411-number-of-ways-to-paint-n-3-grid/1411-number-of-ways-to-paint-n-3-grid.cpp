class Solution {
    private:
    int dp[5001][4][4][4]={};
public:
    int dfs(int n, int a0, int b0, int c0)
    {
        if(n==0)
            return 1;
        if (dp[n][a0][b0][c0] != 0) return dp[n][a0][b0][c0];
        int ans=0;
        int colors[3]={1,2,3};
        for(int a:colors)
        {
            if(a==a0)
                continue;
            for(int b:colors)
            {
                if(b==b0||b==a)
                    continue;
                for(int c:colors)
                {
                    if(c==b||c==c0)
                        continue;
                    ans+=dfs(n-1,a,b,c);
                    ans %= 1000000007;
                }
            }
        }
        return dp[n][a0][b0][c0]=ans;
    }
    
    int numOfWays(int n) {
        return dfs(n,0,0,0);
    }
};