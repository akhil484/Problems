// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>>a)
    {
        // code here
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=a[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    dp[i][j]=max(dp[i][j],max(a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j+1]));
                else if(j==n-1)
                    dp[i][j]=max(dp[i][j],max(a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j-1]));
                else
                {
                    dp[i][j]=max(max(dp[i][j],a[i][j]+dp[i-1][j]),max(a[i][j]+dp[i-1][j-1],a[i][j]+dp[i-1][j+1]));
                }
            }
        }
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(m<dp[n-1][i])
                m=dp[n-1][i];
        }
        return m;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
