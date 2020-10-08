#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int dp[n];
	memset(dp,0,sizeof(dp));
	dp[0]=a[0];
	dp[1]=a[0]+a[1];
	int sum=INT_MIN;
	for(int i=2;i<n;i++)
	{
		dp[i] = max(dp[i-2]+a[i],dp[i-1]);
		if(i>2)
			dp[i]=max(dp[i],dp[i-3]+a[i]+a[i-1]);
		// if(dp[i-1]-dp[i-2]!=a[i-1])
		// {
		// 	dp[i] = max(dp[i],dp[i-1]+a[i]);
		// }
		else
		{
			dp[i] = max(dp[i],a[i]+a[i-1]);
		}

	}
	for(int i=0;i<n;i++)
	{
		if(dp[i]>sum)
			sum=dp[i];
	}
	cout<<dp[n-1]<<"\n";
}