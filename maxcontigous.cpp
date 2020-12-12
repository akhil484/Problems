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

void maxof_sizek(int a[], int n, int k)
{
	int start=0,end=(k-1);
	int h[k];
	for(int i=start;i<=end;i++)
		h[i] = a[i];

	heapify(h,k,0);
	cout<<h[0]<<" ";
	//last = a[start];
    start+= 1;
   end+= 1;
    //nexts = a[end];
    while(end<n)
    {
    	for(int i=0;i<k;i++)
    	{
    		h[i] = a[i+start];
    	}
    	heapify(h,k,0);
		cout<<h[0]<<" ";
		start+= 1;
   		end+= 1;
    }

	
}

int main()
{
	int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n=sizeof(a)/sizeof(a[0]);
	int k=3;
	maxof_sizek(a,n,k);
	return 0;
}