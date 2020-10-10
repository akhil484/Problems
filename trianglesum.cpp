#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> v(n);
	for(int i=0;i<n;i++)
	{
		v[i].resize(i+1);
		for(int j=0;j<=i;j++)
		{
			cin>>v[i][j];
		}
	}
	int dp[n];
	//memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i]=INT_MAX;
	dp[0] = v[0][0];
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i+1] = min(dp[i+1],min(dp[i]+v[i+1][j],dp[i]+v[i+1][j+1]));
		}
	}
	cout<<dp[n-1]<<"\n";
	return 0;
	}