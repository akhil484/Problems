#include<iostream>
using namespace std;

int smallestsumArray(int a[], int n)
{
	int m = a[0];
	int t = a[0];
	for(int i=1;i<n;i++)
	{
		m = min(a[i],a[i]+m);
		t = min(m,t);
	}
	return t;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<smallestsumArray(a,n);
	return 0;
}