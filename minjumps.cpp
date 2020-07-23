#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    //a[0]=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    if(a[0]==0)
	        cout<<-1<<endl;
	    else if(n<=1)
	        cout<<0<<endl;
	    else{
	    int jump[n];
	    jump[0] = 0;
        for(int i=1; i < n ; i++){
            jump[i] = INT_MAX;
        }
	    for(int i=1;i<n;i++)
	    {
	        int j=0;
	        while(i!=j)
	        {
	            if(j+a[j]>=i)
	            {
	                if(jump[i]>jump[j]+1)
	                {
	                    jump[i]=jump[j]+1;
	                }
	            }
	            j++;
	        }
	    }
	    if(jump[n-1]==INT_MAX)
	        cout<<-1<<endl;
	    else
	        cout<<jump[n-1]<<endl;
	    }
	}
	return 0;
}