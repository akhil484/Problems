#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int l1[n1];
	int l2[n2];
	int i=0,j=0,k=l;
	for(int i=0;i<n1;i++)
	{
		l1[i] = a[l+i];
	}
	for(int i=0;i<n2;i++)
		l2[i] = a[m+1+i];
	while(i<n1 && j<n2)
	{
		if(l1[i]<=l2[j])
		{
			a[k] = l1[i];
			k++;
			i++;
		}
		else
		{
			a[k] = l2[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		a[k] = l1[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		a[k] = l2[j];
		k++;
		j++;
	}
}


void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid = l+(r-l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" "<<"\n";
	return 0;
}