#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    long long n;
	    cin>>n;
	   // int count = countfriends(n);
	    
	    long long dp[n+1];
        for(long long i=0;i<=n;i++)
        {
            if(i<=2)
                dp[i] = i;
            else
                dp[i] = (dp[i-1] + ((i-1) * dp[i-2]))%1000000007;
            
        }
        cout<<dp[n]<<endl;
	}
	return 0;
}
