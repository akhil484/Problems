#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		int n;
		cin>>n;
		long long int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		long long int ma = *min_element(a,a+n);
		long long int mb = *min_element(b,b+n);
		long long int count=0;
		for(int i=0;i<n;i++)
		{
			count+=max((a[i]-ma),(b[i]-mb));
		}
		cout<<count<<"\n";
	}
}