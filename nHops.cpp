// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		
		//calling function countWays()
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends


// function to count number of ways to reach top of the stair
long long countWays(int n){
    
    // your code here
    long long c=0;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    long long dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2]=2;
    for(long long i=3;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000007;
    }
    return dp[n];
}
