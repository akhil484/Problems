// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int fm=INT_MIN,sm=INT_MIN;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>fm)
            {
                sm=fm;
                fm=it->second;
            }
            else if(it->second>sm && it->second!=fm)
                sm=it->second;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second==sm)
            {
                return it->first;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
