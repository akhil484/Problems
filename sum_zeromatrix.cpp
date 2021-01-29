#include <bits/stdc++.h>
using namespace std;


bool kad(int arr[], int *start,int *end, int r)
{
    unordered_map<int,int> mp;
    int sum=0;
    int max_len=0;
    for(int i=0;i<r;i++)
    {
    	sum+=arr[i];
    	if(arr[i]==0 && max_len=0)
    	{
    		start=i;
    		end=0;
    		max_len=1;
    	}
    	if(sum==0)
    	{
    		if(max_len<i+1)
    		{
    			start=0;
    			end=i;
    		}
    		max_len=i+1;
    	}
    	if(mp.find(sum)!=mp.end())
    	{
    		int old=max_len;
    		max_len=max(max_len,i-mp[sum]);
    		if(old<max_len)
    		{
    			start=mp[sum]+1;
    			end=i;
    		}
    	}
    	else
    		mp[sum]=i;
    }
    return (max_len!=0);
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
	    int fup = 0, fdown = 0, fleft = 0, fright = 0,up,down;
	    int maxa=INT_MIN;
	    int arr[r];
	    for(int i=0;i<c;i++)
	    {
	        memset(arr,0,sizeof(arr));
	        for(int j=i;j<c;j++)
	        {
	            for(int k=0;k<r;k++)
	                arr[k]+=a[k][j];
	            bool sum = kad(arr,&up,&down,r);
	            int ele = (j-i+1)*(down-up+1);
	            if(sum && ele>maxa)
	            {
	            	maxa=ele;
	            	fup=up;
	            	fdown=down;
	            	fleft=i;
	            	fright=j;
	            }
	        }
	    }
	    if (fup == 0 && fdown == 0 && fleft == 0 && fright == 0 && a[0][0] != 0)
	    	cout << "No zero-sum sub-matrix exists";
	    else
	    {
	    	for(int i=fup;i<=fdown;i++)
	    	{
	    		for(int j=fleft;j<=fright;j++)
	    		{
	    			cout<<a[i][j]<<" ";
	    		}
	    		cout<<endl;
	    	}
	    }
	}
	return 0;
}