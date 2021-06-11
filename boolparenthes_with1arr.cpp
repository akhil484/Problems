// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        // code here
        long long int dp[N][N][2];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i+=2)
        {
            dp[i][i][0]=(S[i]=='F')?1:0;
            dp[i][i][1]=(S[i]=='T')?1:0;
        }
        for(int l=3;l<=N;l+=2)
        {
            for(int i=0;i+l-1<N;i+=2)
            {
                int j=i+l-1;
                for(int k=i+1;k<j;k+=2)
                {
                    long long int ltc=dp[i][k-1][1];
                    long long int rtc=dp[k+1][j][1];
                    long long int lfc=dp[i][k-1][0];
                    long long int rfc=dp[k+1][j][0];
                    if(S[k]=='&')
                    {
                        dp[i][j][1]+=(ltc*rtc)%1003;
                        dp[i][j][0]+=(lfc*rtc)%1003+(ltc*rfc)%1003+(lfc*rfc)%1003;
                    }
                    else if(S[k]=='|')
                    {
                        dp[i][j][1]+=(ltc*rtc)%1003+(lfc*rtc)%1003+(ltc*rfc)%1003;
                        dp[i][j][0]+=(lfc*rfc)%1003;
                    }
                    else
                    {
                        dp[i][j][1]+=(lfc*rtc)%1003+(ltc*rfc)%1003;
                        dp[i][j][0]+=(lfc*rfc)%1003+(ltc*rtc)%1003;
                    }
                }
            }
        }
        return dp[0][N-1][1]%1003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
