// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int n=s.length();
        int r=0,l=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
            {
                maxi=max(maxi,2*r);
            }
            else if(r>l)
                l=r=0;
        }
        l=r=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
            {
                maxi=max(maxi,2*l);
            }
            else if(l>r)
                l=r=0;
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
