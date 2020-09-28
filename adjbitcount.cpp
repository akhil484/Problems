#include<iostream>
#include<string>
#include <cstring>
using namespace std;

int count(int n, int k)
{
	int dp[n+1][k+1][2];
	memset(dp,0,sizeof(dp));
	dp[1][0][0]=1;
	dp[1][0][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0];
			if(j-1>=0)
				dp[i][j][1] += dp[i-1][j-1][1];
		}
	}
	return (dp[n][k][0]+dp[n][k][1]);
}


int main()
{
	int p;
	cin>>p;
	for(int t=0;t<p;t++)
	{
		int dn,n,k;
		cin>>dn>>n>>k;
		int adj_count=0;
		cout<<dn<<" "<<count(n,k)<<endl;
	}
}