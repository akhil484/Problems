#include<iostream>
using namespace std;

int catalant(int n)
{
	int dp[n+1] = {0};
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++)
	{
		int j=0;
		while(j<i)
		{
			dp[i]+=(dp[j]*dp[i-j-1]);
			j++;
		}
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<catalant(n);
	return 0;
}