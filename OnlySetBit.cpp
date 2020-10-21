// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int n) {
        // code here
        if((n&n-1)!=0 || n==0)
            return -1;
        if(n==1)
            return 1;
        int c=0;
        while(n>1)
        {
            int rem=n%2;
            c++;
            n=n/2;
            if(n==1)
                return c+1;
        }
            
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
