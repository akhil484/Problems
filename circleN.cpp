#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int p=2*n;
	int dp[p+1] = {0};
	dp[0] = 1;
	dp[2] = 1;
	for(int i=4;i<=p;i+=2)
	{
		for(int j=0;j<p-1;j+=2)
		{
			dp[i] +=(dp[j]*dp[i-j-2]);
		}
	}
	cout<<dp[p]<<endl;

}