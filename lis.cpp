// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	//code
// 	int tc;
// 	cin>>tc;
// 	for(int t=0;t<tc;t++)
// 	{
// 	    int n;
// 	    cin>>n;
// 	    int a[n];
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        cin>>a[i];
// 	    }
// 	    int dp[n];
// 	    for(int i=0;i<n;i++)
// 	        dp[i]=1;
// 	    for(int i=1;i<n;i++)
// 	    {
// 	        for(int j=0;j<i;j++)
// 	        {
// 	            if(a[j]<a[i])
// 	                dp[i] = max(dp[j]+1,dp[i]);
	            
// 	        }
// 	    }
// 	    int max=INT_MIN;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(max<dp[i])
// 	            max=dp[i];
// 	    }
// 	    cout<<max<<endl;
// 	}
// 	return 0;
// }

//index of dp is the length. For every a[i], see the upper bound.
int dp[n+1];
       for(int i=0;i<n;i++)
    {    dp[i]=INT_MAX;}
        dp[0]=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int idx=upper_bound(dp,dp+n+1,a[i])-dp;
            dp[idx]=a[i];
        }
    for(int i=n;i>=0;i--)
    {
        if(dp[i]!=INT_MAX)
            return i;
    }
