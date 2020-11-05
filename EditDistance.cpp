// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    // Code here
		  //  int ls = s.length();
		  //  int ts = t.length();
		  //  int dp[ls+1][ts+1]; //dp upto length i,j
		  //  for(int i=0;i<=ls;i++)
		  //  {
		  //      for(int j=0;j<=ts;j++)
		  //      {
		  //          if(i==0)        //First string is empty then add all characters of 2nd string
		  //          {
		  //              dp[i][j] = j;
		  //              continue;
		  //          }
		  //          else if(j==0)   //2nd string is empty then remove all characters of first string
		  //          {
		  //              dp[i][j] = i;
		  //          }
		  //          else if(s[i-1]==t[j-1])
		  //          {
		  //              dp[i][j] = dp[i-1][j-1];
		  //          }
		  //          else
		  //          {
		  //              dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));    //Consider all operations and check for minimum of Remove,Replace,Insert Respectively
		  //          }
		  //      }
		  //  }
		  //  return dp[ls][ts];
		  int ls = s.length();
		  int ts = t.length();
		  int dp[2][ls+1];
		  memset(dp,0,sizeof(dp));
		   // Base condition when second string 
          // is empty then we remove all characters 
		  for(int i=0;i<=ls;i++)
		  {
		      dp[0][i]=i;
		  }
		  for(int i=1;i<=ts;i++)
		  {
		      for(int j=0;j<=ls;j++)
		      {
		          if(j==0)
		            dp[i%2][0] = i;
		          else if(s[j-1]==t[i-1])
		          {
		              dp[i%2][j] = dp[(i-1)%2][j-1];
		          }
		          else
		          {
		              dp[i%2][j] = 1+min(dp[(i-1)%2][j],min(dp[(i-1)%2][j-1],dp[i%2][j-1]));
		          }
		      }
		  }
		  return dp[ts%2][ls];
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends
