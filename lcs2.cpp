#include <iostream>
#include<cstring>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n,m;
	    cin>>n>>m;
	    string x,y;
	    cin>>x;
	    cin>>y;
	    int mlen=0;
	    int dp[n+1][m+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(x[i-1]==y[j-1])
	            {
	                dp[i][j] = 1+dp[i-1][j-1];
	            }
	            else
	                dp[i][j] = 0;
	            if(mlen<dp[i][j])
	                mlen=dp[i][j];
	        }
	    }
	    cout<<mlen<<"\n";
	}
	return 0;
}
