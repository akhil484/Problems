#include <iostream>
using namespace std;

int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n][m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int dp[n][m];
	    int ma=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            dp[i][j]=0;
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j]=a[i][j];
	            }
	            else
	            {
	                if(a[i][j]==0)
	                    dp[i][j]=0;
	                else
	                {
	                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
	                }
	            }
	            if(ma<dp[i][j])
	                ma=dp[i][j];
	        }
	    }
	    cout<<ma<<"\n";
	}
	return 0;
}
