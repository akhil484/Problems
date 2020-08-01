#include <iostream>
using namespace std;
int p=1e9+7;
int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
}
int coefficient(int n, int r)
{
    int *c=new int[r+1]();
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
        {
            
            c[j]=(c[j-1]+c[j])%(p);
            
        }
    }
    return c[r];
}


int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n,r;
	    cin>>n>>r;
	    cout<<coefficient(n,r)<<endl;
	}
	return 0;
}