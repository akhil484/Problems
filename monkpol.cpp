#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long int a,b,c,k,ans=0;
		cin>>a>>b>>c>>k;
		long long int l=0,h=100000,m=(h+l)/2;
		while(h>=l)
		{
			if(((a*m*m)+(b*m)+c)>=k)
			{
				ans=m;
				h=m-1;
			}
			else
				l=m+1;
			m=(h+l)/2;
		}
		cout<<ans<<endl;
	}
}