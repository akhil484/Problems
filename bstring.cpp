#include<iostream>
using namespace std;

void print(int a[],int k)
{
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
	}
	cout<<"\n";
}

void bstring(int k,int a[], int len)
{
	if(len == k)
	{
		print(a,k);
		return;
	}
	if(a[len-1]==1)
	{
		a[len] = 0;
		bstring(k,a,len+1);
	}
	if(a[len-1] == 0)
	{
		a[len] = 0;
		bstring(k,a,len+1);
		a[len] = 1;
		bstring(k,a,len+1);
	}
}

int main()
{
	int k;
	cout<<"Enter the value of k"<<" ";
	cin>>k;
	int len=1;
	int a[k];
	a[0]=0;
	bstring(k,a,len);
	a[0]=1;
	bstring(k,a,len);
}