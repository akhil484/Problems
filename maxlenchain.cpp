// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool compst(val a,val b)
{
    return (a.second<b.second); 
}
int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p,p+n,compst);
int c=1,index=0;
for(int i=1;i<n;i++)
{
    if(p[index].second<p[i].first)
    {
        c++;
        index=i;
    }
}
return c;
}
