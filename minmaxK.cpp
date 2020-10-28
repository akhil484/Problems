#include<iostream>
#include<algorithm>
#include <limits.h>
using namespace std;

int sendIndex(int start,int end,int k, int a[], int key)
{
	int mid,ind=-1;
	while(start<end)
	{
		mid = start+(end-start)/2;
		if(a[mid]-key<=k)
		{
			ind=mid;
			start=mid+1;		//minimum removals will occur when the interval is as large as possible
		}
		else
			end=mid;
	}
	return ind;
}

void findrem(int a[],int k,int n)
{
	sort(a,a+n);
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int j=sendIndex(i+1,n-1,k,a,a[i]);
		if(j!=-1)
		{
			ans  = min(ans,n-(j+1-i));
		}

	}
	cout<<ans;
}

int main()
{
	int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"n inside main"<<n<<endl;
	int k=4;
	findrem(a,k,n);
	return 0;
}