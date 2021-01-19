#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n,m;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cin>>m;
	    int d=INT_MAX;
	    sort(a,a+n);
	    for(int i=0;i+m-1<n;i++)
	    {
	        if(d>(a[i+m-1]-a[i]))
	            d=a[i+m-1]-a[i];
	    }
	    cout<<d<<endl;
	}
	return 0;
}
