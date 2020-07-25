#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n;
	    cin>>n;
	    int a[n+2];
	    for(int i=0;i<n+2;i++)
	    {
	        cin>>a[i];
	    }
	    int *count=new int[n+1]();
	    for(int i=0;i<n+2;i++)
	    {
	        if(count[a[i]]==1)
	        {
	            cout<<a[i]<<" ";
	            continue;
	        }
	        count[a[i]]=1;
	    }
	    cout<<endl;
	}
	return 0;
}