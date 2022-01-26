class Solution {
public:
    int maxp(vector<int>& p, int res = 0) {
        for (int i = 1; i < p.size(); ++i) 
            res += max(0, p[i] - p[i - 1]);
        return res;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
            if(k>=n/2)
            return maxp(prices);
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for(int i=1;i<=k;i++)
        {
            int maxdiff = INT_MIN;
            for(int j=1;j<n;j++)
            {
                maxdiff = max(maxdiff,dp[i-1][j-1]-prices[j-1]);
                dp[i][j] = max(dp[i][j-1],maxdiff+prices[j]);
                
            }
        }
        return dp[k][n-1];
    }
};