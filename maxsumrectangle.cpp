#include <bits/stdc++.h>
using namespace std;

int kad(int arr[], int r)
{
    int max_so_far=arr[0],max_ending_here=arr[0];
    for(int i=1;i<r;i++)
    {
        
        max_ending_here=max(arr[i],max_ending_here+arr[i]);
        max_so_far=max(max_so_far,max_ending_here);
    }
    
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
        int arr[C];
        for(int i=0;i<R;i++)
        {
            memset(arr,0,sizeof(arr));
            for(int j=i;j<R;j++)
            {
                for(int k=0;k<C;k++)
                {
                    arr[k]+=M[j][k];
                }
                ans=max(ans,kad(arr,C));
            }
        }
	    cout<<ans<<endl;
	}
	return 0;
}
