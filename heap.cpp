#include<iostream>
using namespace std;

void heapify(int a[],int n,int i)
{
	int largest=i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n&&a[largest]<a[l])
	{
		largest=l;
	}
	if(r<n&&a[largest]<a[r])
	{
		largest=r;
	}
	if(largest!=i)
	{
		int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		heapify(a,n,largest);
	}
}



void heapsort(int a[],int n)
{
	for(int i=(int(n/2)-1);i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(int i=(n-1);i>=0;i--)
	{
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}
}


void print_a(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	int a[]={5,2,8,23,9,6,1,134,55,643,4};
	int n=sizeof(a)/sizeof(a[0]);
	heapsort(a,n);
	cout<<"Sorted Array:"<<"\n";
	print_a(a,n);

	return 0;
}