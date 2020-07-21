#include<iostream>
using namespace std;

int maxprice(int a[],int n)
{
	int *profit=new int[n]();
	int max_price=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(max_price<a[i])
			max_price=a[i];
		profit[i]=max(profit[i+1],max_price-a[i]);
	}
	int min_price=a[0];
	for(int i=1;i<n;i++)
	{
		if(min_price>a[i])
			min_price=a[i];
		profit[i]=max(profit[i-1],profit[i]+(a[i]-min_price));
	}
	return profit[n-1];
}


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int result=maxprice(a,n);
	cout<<result<<endl;
}