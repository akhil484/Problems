#include <iostream>
using namespace std;
int countcoin(int a[],int n,int m)
{
    int *table=new int[m+1]();
    table[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=m;j++)
        {
            table[j]+=table[j-a[i]];
        }
        
    }
    return table[m];
}
int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n,m;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        cout<<countcoin(a,n,m)<<endl;
    }
	
	return 0;
}