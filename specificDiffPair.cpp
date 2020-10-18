#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int x;
	    cin>>x;
	    sort(a,a+n);
	    int sum=0;
	    for(int i=n-1;i>0;i--)
	    {
	        if(a[i]-a[i-1]<x)
	        {
	            sum +=a[i]+a[i-1];
	            i--;
	        }
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}
