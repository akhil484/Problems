// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int find(int a[],int size)
{
    int mj=0,count=1;
    for(int i=1;i<size;i++)
    {
        if(a[i]==a[mj])
            count++;
        else
            count--;
        if(count==0)
        {
            mj=i;
            count=1;
        }
    }
    return a[mj];
}
bool majority(int a[], int size, int c)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==c)
            count++;
    }
    if(count>(size/2))
        return 1;
    else 
        return 0;
}
int majorityElement(int a[], int size)
{
    
    // your code here
    int cand=find(a,size);
    if(majority(a,size,cand))
        return cand;
    else
        return -1;
    
    
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
