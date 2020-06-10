#include<iostream>
using namespace std;

void check(int a[], int n)
{
	int sum1=0, sum2=0;
	for(int i=0;i<(n/2);i++)
	{
		sum1+=a[i];
		sum2+=a[i+(n/2)];
	}
	if(sum1==sum2)
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i];
		}
		cout<<"\n";
	}
}

void bsum(int n, int a[], int len)
{
	if(len==n)
	{
		check(a,n);
		return;
	}

	a[len] = 1;
	bsum(n,a,len+1);
	a[len] = 0;
	bsum(n,a,len+1);
}

int main()
{
	int n;
	cout<<"Enter the value of n"<<" ";
	cin>>n;
	int len = 1;
	int a[n];
	a[0] = 1;
	bsum(n,a,len);
}