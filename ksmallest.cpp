#include<iostream>
using namespace std;

void heapify(int *a,int n,int i)
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





int kthSmallest(int arr[], int l, int r, int k) {
    int h[k];
    
    for(int i=0;i<k;i++)
        h[i] =  arr[i];
    int startindex=(k/2)-1;
	for(int i=startindex;i>=0;i--)
		heapify(h,k,i);
    
    for(int i=k;i<=r;i++)
    {
        if(arr[i]<h[0])
        {
            h[0] = arr[i];
		    heapify(h,k,0);
        }
    }
    return h[0];
}

	int main(){
	int arr[] = { 7, 10, 4, 20, 15 }; 
    int n = sizeof(arr) / sizeof(arr[0]), k = 4; 
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k); 
    return 0;
   }