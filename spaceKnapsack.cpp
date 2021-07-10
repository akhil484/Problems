int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[2][W+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i==0||j==0)
                    dp[i%2][j]=0;
               else if(wt[i-1]<=j)
               {
                   dp[i%2][j]=max(dp[(i-1)%2][j],val[i-1]+dp[(i-1)%2][j-wt[i-1]]);
               }
               else
                    dp[i%2][j]=dp[(i-1)%2][j];
           }
       }
       return dp[n%2][W];
    }
