// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        // string s;
        // string c;
        // while(N!=1)
        // {
        //     c=to_string(N%2);
        //     N=N/2;
        //     s=c+s;
        // }
        // s=to_string(N)+s;
        // //cout<<s<<endl;
        int count=0;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i]=='1')
        //         count+=1;
        // }
        while(N)
        {
            N &=N-1;
            count++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends
