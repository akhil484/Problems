#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
		int n,m;
		cin>>n>>m;
		int a[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				if((i+j)%2==0)
				{
					if(a[i][j]%2!=0)
						a[i][j]++;

				}
				else
				{
					if(a[i][j]%2==0)
						a[i][j]++;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
}