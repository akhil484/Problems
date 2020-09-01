#include <bits/stdc++.h> 
using namespace std;

int main() {
	//code
	int test_cases;
	cin>>test_cases;
	for(int t=0;t<test_cases;t++)
	{
	    int n,x,y,z;
	    cin>>n;
	    cin>>x>>y>>z;
	    int a[n+1];
	    memset(a,-1,sizeof(a));				//-1 because there will be lengths not equal to i+p,i+q,i+r so they should be discarded
	    a[0] = 0;
	    for(int i=0;i<=n;i++)
	    {
	        if(a[i]==-1)
	        {
	            continue;
	        }
	        else
	        {
	            if(i+x<=n)
	                a[i+x] = max(a[i+x],a[i]+1);
	            if(i+y<=n)
	                a[i+y] = max(a[i+y],a[i]+1);
	            if(i+z<=n)
	                a[i+z] = max(a[i+z],a[i]+1);
	        }
	        //cout<<a[i]<<endl;
	        
	    }
	    cout<<a[n]<<endl;
	}
	return 0;
}
