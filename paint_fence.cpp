#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test_cases;
	cin>>test_cases;
	for(int z=0;z<test_cases;z++)
	{
	    int n,k;
	    cin>>n>>k;
	    //cout<<n<<endl;
	    long dp[n+1];
	    memset(dp,0,sizeof(dp));
	    dp[1] = k;
	    dp[2] = k*k;    //k+k*(k-1)
	    //total[i] = same[i]+diff[i]
	    //same[i] = diff[i-1]*1
	    //diff[i] = total[i-1]*(k-1)
	    //total[i] = diff[i-1]+total[i-1]*(k-1)
	    //total[i] = total[i-2]*(k-1) + total[i-1]*(k-1)
	    for(int i=3;i<=n;i++)
	    {
	        dp[i] = ((k-1)*(dp[i-1]+dp[i-2]))%1000000007;
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}