// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int dp[W+1];
        dp[0]=0;
        //memset(dp,INT_MAX,sizeof(dp));
        for(int i=1;i<=W;i++)
            dp[i]=INT_MAX;
        for(int i=1;i<=W;i++)
        {
            for(int j=0;j<N;j++)
            {
                if((j+1)<=i && cost[j]!=-1 && dp[i - (j + 1)] != INT_MAX)
                {
                    dp[i] = min(dp[i],cost[j]+dp[i-(j+1)]);
                }
            }
        }
        if(dp[W]==INT_MAX)
            return -1;
        else
            return dp[W];
	}

};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
