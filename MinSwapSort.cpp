// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int n){
    /*Your code here */
    
    pair<int,int>a[n];
    for(int i=0;i<n;i++)
    {
        a[i].first=arr[i];
        a[i].second=i;
    }
    sort(a,a+n);                    //Now elements are at place where they should be and also contain their older position.
    vector<bool> v(n,false);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]||a[i].second==i)    //Either they have already been visited or they are already at right place.
            continue;
        else
        {
            int cycle_size=0;
            int j=i;
            while(!v[j])
            {
                v[j]=1;
                cycle_size++;
                j=a[j].second;
            }
            if(cycle_size>0)
            {
                ans +=(cycle_size-1);
            }
        }
    }
    return ans;
}
