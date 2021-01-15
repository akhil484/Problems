// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}// } Driver Code Ends




int sb(int arr[], int n, int x)
{
    // Your code goes here
    int l=n+1,csum=0;
    int start=0,end=0;
    while(end<n)
    {
        while(csum<=x&&end<n)
            csum+=arr[end++];
        while(csum>x && start<n)
        {
            if(end-start<l)
                l=end-start;
            csum-=arr[start++];
        }
    }
    return l;
}
