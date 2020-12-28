#include<iostream>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		int n,x,y;
		cin>>n>>x>>y;
		int dp[n+1];
		dp[0]=false;	//0 coins. Nothing to pick so A will not win
		dp[1]=true;
		for(int i=2;i<=n;i++)
		{
			if(i-1>=0 && !dp[i-1])
				dp[i]=true;
			else if(i-x>=0 && !dp[i-x])
				dp[i]=true;
			else if(i-y>=0 && !dp[i-y])
				dp[i]=true;
			else
				dp[i]=false;
		}
		cout<<dp[n]<<endl;
	}
}