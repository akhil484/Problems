class Solution {
public:
    int dp[1001][2001]={};
    int calc(vector<vector<int>>& piles, int k, int i)
    {
        if(i==piles.size()||k==0)
            return 0;
        if(dp[i][k]==0)
        {
            int sum = 0;
            for(int j=0;j<=piles[i].size()&&k-j>=0;j++)
            {
                dp[i][k] = max(dp[i][k],sum+calc(piles,k-j,i+1));
                if(j<piles[i].size())
                    sum+=piles[i][j];
            }
        }
        return dp[i][k];
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       
        return calc(piles,k,0);
    }
};