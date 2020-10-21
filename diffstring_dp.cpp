#include<iostream>
#include <cstring>
#include <limits.h>
using namespace std;

bool allones(string s,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			c++;
		}
	}
	if(c==n)
		return true;
	else
		return false;
}

int maxlen(int a[],string s,int n,int ind,int st,int dp[][2])
{
	if(ind>=n)
		return 0;
	if(dp[ind][st]!=-1)
		return dp[ind][st];

	if(st==0)
		return dp[ind][st]=max(a[ind]+maxlen(a,s,n,ind+1,1,dp),maxlen(a,s,n,ind+1,0,dp));
	else
	{
		return dp[ind][st] = max(a[ind]+maxlen(a,s,n,ind+1,1,dp),0);
	}
}

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(allones(s,n))
		cout<<-1<<endl;
	else
	{
		int a[n];
		for(int i=0;i<n;i++)
		{
			a[i]=(s[i]=='0'?1:-1);
		}
		int dp[n][2];
		memset(dp,-1,sizeof(dp));
		cout<<maxlen(a,s,n,0,0,dp);
	}
	return 0;
}