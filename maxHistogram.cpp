// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<int> s;
    long long max_area=0,at,tp;
    int i=0;
    while(i<n)
    {
        if(s.empty() || arr[s.top()]<=arr[i])
            s.push(i++);
        else
        {
            tp=s.top();
            s.pop();
            at = arr[tp]*(s.empty()?i:(i-s.top()-1));
            if(max_area<at)
                max_area=at;
        }
    }
    while(s.empty()==false)
    {
            tp=s.top();
            s.pop();
            at = arr[tp]*(s.empty()?i:(i-s.top()-1));
            if(max_area<at)
                max_area=at;
    }
    return max_area;
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
