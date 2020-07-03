#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int flag=0;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		a[a[i]%n]+=n;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]/n>1)
		{
			cout<<i<<endl;
			flag++;
		}
	}
	if(flag==0)
		cout<<-1<<endl;
}