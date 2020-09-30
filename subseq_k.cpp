#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int c=0;
	int a[n];
	int dp[k+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j] = dp[i][j-1];
			if(a[j-1]<=i && a[j-1]>0)
			{
				dp[i][j] += dp[i/a[j-1]][j-1]+1;
			}
			
		}
	}
	cout<<"All subsequences having product less than "<<k<<" is "<<dp[k][n]<<"\n";
}