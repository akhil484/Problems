#include<bits/stdc++.h>
#include<stack>
using namespace std;

void fillit(int a[],int next[],int n)
{
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		cout<<"inside fillit for"<<endl;
		while(!s.empty())
		{
			int cur=s.top();
			if(a[i]>a[cur])
			{
				next[cur]=i;
				s.pop();
			}
			else
				break;

		}
		s.push(i);
	}
	while(!s.empty())
	{
		next[s.top()]=-1;
		s.pop();
	}
}

void count(int a[],int dp[],int n)
{
	int next[n];
	memset(next,0,n);
	fillit(a,next,n);
	for(int i=0;i<n;i++)
	{
		cout<<next[i]<<" ";
	}
	cout<<endl;
	for(int i=n-2;i>=0;i--)
	{
		cout<<"Inside Count"<<endl;
		if(next[i]==-1)
			dp[i]=0;
		else
			dp[i]=dp[next[i]]+1;
	}
}

int main()
{
	cout<<"start main"<<endl;
	int n,q;
	
	cin>>n>>q;
	int a[n];
	int dp[n];
	int query[q];
	memset(dp,0,n);
	cout<<"before taking input"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"before taking query"<<endl;
	for(int i=0;i<q;i++)
	{
		cin>>query[i];
	}
	int index=0;
	cout<<"before count"<<endl;
	count(a,dp,n);
	while(index<q)
	{
		cout<<dp[query[index]]<<endl;
		index++;
	}
	return 0;
}