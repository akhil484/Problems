class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int dp[n][n];
        for(int l=0;l<n;l++)
        {
            for(int i=0;(i+l)<n;i++)
            {
                int j=i+l;
                dp[i][j]=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int left = (k==i)? 0:dp[i][k-1];    //if k is starting of an array then there is nothing before it.
                    int right = (k==j)? 0:dp[k+1][j];   //if k is end of array then there is nothing after it.
                    int val = (i==0?1:nums[i-1]) * nums[k] * (j==n-1?1:nums[j+1]);
                    int total = left + right + val;
                    if(total>dp[i][j])
                        dp[i][j] = total;
                }
            }
        }
        
        return dp[0][n-1];
        
    }
};
