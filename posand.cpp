#include<bits/stdc++.h>
using namespace std;


int main()
{
	int tc;
	cin>>tc;
	while(tc>0)
	{
		long long int n;
		cin>>n;
		if(n==1)
		{
			cout<<"1\n";
		}
		else if(ceil(log2(n))==floor(log2(n)))
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<"2 3 1 ";
			for(int i=4;i<=n;i++)
			{
				if(ceil(log2(i))==floor(log2(i)))
				{
					cout<<i+1<<" "<<i<<" ";
					i++;
				}
				else
					cout<<i<<" ";
			}
			cout<<"\n";
		}
		tc--;
	}
	return 0;
}