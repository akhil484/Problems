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
	    int dp[n];
	    for(int i=0;i<n;i++)
	        dp[i]=1;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i])
	                dp[i] = max(dp[j]+1,dp[i]);
	            
	        }
	    }
	    int max=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        if(max<dp[i])
	            max=dp[i];
	    }
	    cout<<max<<endl;
	}
	return 0;
}