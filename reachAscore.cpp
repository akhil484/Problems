#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n;
	    cin>>n;
	    int dp[n+1];
	    memset(dp,0,sizeof(dp));
	    dp[0]=1;
	    for(int i=3;i<=n;i++)
	        dp[i]+=dp[i-3];
	    for(int i=5;i<=n;i++)
	        dp[i]+=dp[i-5];
	    for(int i=10;i<=n;i++)
	        dp[i]+=dp[i-10];
	    cout<<dp[n]<<"\n";
	}
	return 0;
}
