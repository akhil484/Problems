#include<iostream>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int dp[n];
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<n;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	for(int i=n-1;i>=0;i--)
	{
		cout<<dp[i]<<" ";
	}
}