// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int minTimeForWritingChars(int N, int I, 
                       int D, int C) 
	{ 
	    // Your code goes here
	    if(N==0)
	        return 0;
	    if(N==1)
	        return I;
	    int dp[N+1];
	    int fl,cl;
	    
	    for(int i=0;i<=N;i++)
	        dp[i] = 0;
	    dp[1] = I;
	    for(int i=2;i<=N;i++)
	    {
	        int i_insert = dp[i-1]+I;
	        int i_cpd = 0;
	        if(i%2==0)
	            i_cpd = dp[i/2]+C;
	        else
	        {
	            //fl = floor(i/2);  this case is same as (i-1)+I case
	            cl=((i+1)/2);
	            i_cpd = (dp[cl]+C+D);
	        }
	        //cout<<i_insert<<" "<<i_cpd<<endl;
	        dp[i] = min(i_insert,i_cpd);
	    }
	    
	    return dp[N];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, i, d, c;
        cin >> n >> i >> d >> c;

	    Solution ob;
	    cout << ob.minTimeForWritingChars(n, i, d, c) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
