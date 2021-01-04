#include <bits/stdc++.h>
using namespace std;
bool checkT(int a[], int n, int k)
{
    int l,r;
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        l=i+1;
        r=n-1;
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==k)
                return true;
            else if(a[i]+a[l]+a[r]<k)
                l++;
            else
                r--;
        }
    }
    return false;
}

int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    if(checkT(a,n,k))
	        cout<<1<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}
