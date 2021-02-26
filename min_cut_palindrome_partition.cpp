// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        bool pal[n][n];
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    pal[i][j]=true;
                }
                else if (g==1)
                {
                    if(str[i]==str[j])
                        pal[i][j]=true;
                    else
                        pal[i][j]=false;
                }
                else
                {
                    if(str[i]==str[j] && pal[i+1][j-1])
                        pal[i][j]=true;
                    else
                        pal[i][j]=false;
                }
            }
        }
        // int cuts[n][n];
        // for(int g=0;g<n;g++)
        // {
        //     for(int i=0,j=g;j<n;i++,j++)
        //     {
        //         if(g==0)
        //             cuts[i][j]=0;
        //         else if(g==1)
        //         {
        //             if(str[i]==str[j])
        //                 cuts[i][j]=0;
        //             else
        //                 cuts[i][j]=1;
        //         }
        //         else
        //         {
        //             if(pal[i][j])
        //                 cuts[i][j]=0;
        //             else
        //             {
        //                 int mc=INT_MAX;
        //                 for(int k=i;k<j;k++)
        //                 {
        //                     int left=cuts[i][k];
        //                     int right=cuts[k+1][j];
        //                     if(left+right+1<mc)
        //                         mc=left+right+1;
        //                 }
        //                 cuts[i][j]=mc;
        //             }
        //         }
        //     }
        // }
        // return cuts[0][n-1];
        
        int cuts[n];
        cuts[0]=0;
        for(int j=1;j<n;j++)
        {
            if(pal[0][j])
                cuts[j]=0;
            else
            {
            int mc=INT_MAX;
            for(int i=j;i>=1;i--)
            {
                if(pal[i][j])
                {
                    if(cuts[i-1]<mc)
                        mc=cuts[i-1];
                }
            }
            cuts[j]=mc+1;
            }
        }
        return cuts[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
