#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n,i;
	    cin>>n;
	    long long arr[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    long long max_here=arr[0],min_here=arr[0],max_global=arr[0]%1000000007;
	    for(i=1;i<n;i++)
	    {
	        long long temp=max_here;
	        max_here=max(arr[i],max(arr[i]*max_here,arr[i]*min_here))%1000000007;
	        min_here=min(arr[i],min(arr[i]*temp,arr[i]*min_here))%1000000007;
	        if(max_here>max_global)
	            max_global=max_here;
	    }
	    cout<<max_global<<endl;
	}
	return 0;
}