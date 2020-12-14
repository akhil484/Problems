#include <iostream>
#include <vector>
using namespace std;

void heapify(int q[], int n , int i)
{
    
    int largest = i;
    int lr = 2*i+2;
    int ll = 2*i+1;
    if(ll<n && q[largest]<q[ll])
        largest=ll;
    if(lr<n && q[largest]<q[lr])
        largest=lr;
    if(largest!=i)
    {
        int temp=q[i];
        q[i] = q[largest];
        q[largest]=temp;
        heapify(q,n,largest);
    }
}


int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n],b[m];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int j=0;j<m;j++)
	    {
	        cin>>b[j];
	    }
	    int q[n+m];
	    for(int i=0;i<n;i++)
	    {
	        q[i]=a[i];
	    }
	    for(int i=0;i<m;i++)
	    {
	        q[n+i]=b[i];
	    }
	    for(int i=((n+m));i>=0;i--)
	    {
	        heapify(q,(n+m),i);
	    }
	    for(int i=0;i<(n+m);i++)
	    {
	        cout<<q[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
