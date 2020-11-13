// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) 
{
    // your code here
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i==1)
            {
                dp[i][j]=j;
            }
            else if(j==1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int min_value = INT_MAX;
                for(int a=j-1,b=0;a>=0;a--,b++)
                {
                    int v1 = dp[i][a]; //egg survives
                    int v2 = dp[i-1][b]; //egg breaks
                    int v = max(v1,v2);
                    min_value = min(v,min_value);
                }
                dp[i][j] = min_value+1; //1 attempt is reaching to that level
            }
            
            
        }
    }
    return dp[n][k];
}

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
