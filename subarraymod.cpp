#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
		long long n,m;
		cin>>n>>m;
		long long a[1+n];
		a[0]=0;
		long long maxval=-1;
		set<long long> s;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]=(a[i]+a[i-1])%m;
			s.insert(a[i]);
			set<long long> :: iterator it=s.lower_bound(a[i]+1);
			if(it!=s.end())
				maxval=max(maxval,(a[i]+m-(*it))%m);
			else
				maxval=max(a[i]%m,maxval);
		}
		cout<<maxval<<endl;
	}
}