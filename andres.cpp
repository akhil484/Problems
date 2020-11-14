#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			a[i] = 1;
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}