// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    ll FindMaxSum(ll arr[], ll n)
    {
        // Your code here
        // if(n==1)
        //     return arr[0];
        // if(n==2)
        //     return (arr[0]>=arr[1]?arr[0]:arr[1]);
        // ll dp[n];
        // dp[0]=arr[0];
        // dp[1]=max(arr[0],arr[1]);
        
        // for(ll i=2;i<n;i++)
        // {
        //     dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
           
        // }
        // return dp[n-1];
        ll incl=arr[0];
        ll excl=0;
        for(ll i=1;i<n;i++)
        {
            ll new_sum=max(excl,incl);
            
            incl=arr[i]+excl;
            excl=new_sum;
            
        }
        return max(excl,incl);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
