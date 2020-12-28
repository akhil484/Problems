#include<iostream>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(n==1)
			cout<<a[0]<<endl;
		else{
			int m=INT_MIN,p=1;
			int count_neg=0,count_zero=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				count_zero++;
				continue;
			}

			if(a[i]<0)
			{
				count_neg++;
				m=max(m,a[i]);
			}
			p=p*a[i];
		}
		if(count_zero==n)
			cout<<0<<endl;
		if(count_neg&1)
		{
			if(count_neg==1&&count_zero>0&& (count_neg+count_zero)==n)
				p=0;
			else
				p=p/m;
			
		}
		cout<<p<<endl;
	}
		}
		return 0;
		
}