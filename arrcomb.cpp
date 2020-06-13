//Print all possible combinations of r elements in a given array of size n

#include<iostream>
using namespace std;

void print(int res[], int r)
{
	cout<<"(";
	for(int i=0;i<r;i++)
	{
		cout<<res[i];
		if(i!=(r-1))
		{
			cout<<",";
		}

	}
	cout<<")";
	cout<<"\n";
}

void arrcomb(int a[], int res[], int i, int n, int r, int len)
{
	if(len==r)
	{
		print(res,r);
		return;
	}


	for(int j=i;j<=n;j++)
	{
		if(res[len-1]<a[j])
		{
			res[len] = a[j];
			arrcomb(a,res,i+1,n,r,len+1);
		}
	}
}

int main()
{
	int n,r;
	cout<<"Enter the values of n and r"<<" ";
	cin>>n>>r;
	int a[n];
	int res[r];
	cout<<"Enter the values in array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	arrcomb(a,res,0,n-1,r,0);
}