// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int xo=arr[0];
        for(int i=1;i<n;i++)
        {
            xo^=arr[i];
        }
        for(int i=1;i<=n;i++)
        {
            xo^=i;
        }
        int sbn=xo&~(xo-1);
        int xs=0,xns=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&sbn)
            {
                xs^=arr[i];
            }
            else
            {
                xns^=arr[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i&sbn)
            {
                xs^=i;
            }
            else
            {
                xns^=i;
            }
        }
        int* a = new int[2];
        a[0]=xs;
        a[1]=xns;
        for(int i=0;i<n;i++)
        {
            if(a[1]==arr[i])
            {
                swap(a[0],a[1]);
                break;
            }
        }
        
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
