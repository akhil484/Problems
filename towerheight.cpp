#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n,k;
	    cin>>k;
	    cin>>n;
	    int a[n];
	    int maxval=INT_MIN;
	    int minval=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]>maxval)
	            maxval=a[i];
	        if(a[i]<minval)
	            minval=a[i];
	    }
	    int mid=(minval+maxval)/2;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>mid)
	            a[i]-=k;
	        else
	            a[i]+=k;
	    }
	    int maxval1=INT_MIN;
	    int minval1=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>maxval1)
	            maxval1=a[i];
	        if(a[i]<minval1)
	            minval1=a[i];
	    }
	    cout<<min(maxval-minval,maxval1-minval1)<<endl;
	}
	return 0;
}