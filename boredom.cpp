#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	long long c[100005];
	long long dp[100005];
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)
		c[a[i]]++;
	dp[0] = 0;
	dp[1] = c[1]*1;						//For a sequence of number containing only the numbers, 0,1
	for(int i=2;i<=100000;i++)				//For a sequence of number containing only the numbers, 0 to n, we can either pick the nth element, or not.
	{
		dp[i] = max(dp[i-1],i*c[i]+dp[i-2]);		//if one chooses i then i-1 will be removed and if one chooses i-1 then i will be removed

	}
	cout<<dp[100000];
}
