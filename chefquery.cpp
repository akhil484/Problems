#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		int flag=0;
		long long int n,k;
		cin>>n>>k;
		long long int q[n];
		long long int temp = 0;
		long long int c=0;
		for(long long int i=0;i<n;i++)
		{
			cin>>q[i];
			temp +=q[i];

		}
		long long int res = 0;
		for(long long int i=0;i<n;i++)
		{
			res +=q[i];
			if(res<k)
			{
				c++;
				res=0;
				break;
			}
			res -=k;
			c++;
		}
		if(res!=0)
		{
			c=(temp/k)+1;
		}
		cout<<c<<endl;
	}
	return 0;
}