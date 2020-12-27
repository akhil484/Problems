// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int maxProfit(int K, int N, int A[])
    {
        // code here
        if(N==0)
            return 0;
        int profit[K+1][N];
        for(int i=0;i<=K;i++)
        {
            for(int j=0;j<N;j++)
            {
                profit[i][j]=0;
            }
        }
        for(int i=1;i<=K;i++)
        {
            int mtf=INT_MIN;
            for(int j=1;j<N;j++)
            {
                mtf=max(mtf,profit[i-1][j-1]-A[j-1]);
                profit[i][j]=max(profit[i][j-1],mtf+A[j]);
            }
        }
        return profit[K][N-1];
        //2nd option space optimized
        if(N==0)
            return 0;
        int profit[2][N];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<N;j++)
            {
                profit[i][j]=0;
            }
        }
        bool b;
        for(int i=1;i<=K;i++)
        {
            b = i&1;
            int mtf=INT_MIN;
            for(int j=1;j<N;j++)
            {
                mtf=max(mtf,profit[1-b][j-1]-A[j-1]);
                profit[b][j]=max(profit[b][j-1],mtf+A[j]);
            }
        }
        return profit[b][N-1];
    }
};

// { Driver Code Starts.
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>K;
        cin>>N;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.maxProfit(K, N, A)<<endl;
    }
    return 0; 
}  // } Driver Code Ends
