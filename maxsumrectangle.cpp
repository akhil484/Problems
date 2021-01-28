#include <bits/stdc++.h>
using namespace std;

int kad(int arr[], int r)
{
    int m=INT_MAX,count=0,max_so_far=0,max_ending_here=0;
    for(int i=0;i<r;i++)
    {
        if(arr[i]<0)
            count++;
        if(arr[i]<m)
            m=arr[i];
        max_ending_here+=arr[i];
        if(max_ending_here<0)
            max_ending_here=0;
        if(max_so_far<max_ending_here)
            max_so_far=max_ending_here;
    }
    if(count==r)
        return m;
    else
        return max_so_far;
    
}

int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int r,c;
	    cin>>r>>c;
	    int a[r][c];
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    int ans=INT_MIN;
	    int arr[r];
	    for(int i=0;i<c;i++)
	    {
	        memset(arr,0,sizeof(arr));
	        for(int j=i;j<c;j++)
	        {
	            for(int k=0;k<r;k++)
	                arr[k]+=a[k][j];
	            ans=max(ans,kad(arr,r));
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
