#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX

void print(int p[], int n)
{
    if(p[n]==1)
        cout<<p[n]<<" "<<n<<" ";
    else
    {
        print(p,p[n]-1);
        cout<<p[n]<<" "<<n<<" ";
    }
}

int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n;
	    cin>>n;
	    int a[n+1];
	    for(int i=1;i<=n;i++)
	        cin>>a[i];
	    int m;
	    cin>>m;
	    int space[n+1][n+1];
	    int ls[n+1][n+1];
	    int c[n+1];
	    int p[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        space[i][i]=m-a[i];
	        for(int j=i+1;j<=n;j++)
	        {
	            //space remaining in previous arrangement then include a[j] and minus 1 for space;
	            space[i][j] = space[i][j-1] - a[j] - 1;
	            
	        }
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=i;j<=n;j++)
	        {
	            if(space[i][j]<0)
	                ls[i][j]=inf;
	            else if(j==n&&space[i][j]>=0)
	                ls[i][j]=0;       //last line
	            else
	            {
	                ls[i][j] = space[i][j]*space[i][j];
	            }
	        }
	    }
	    c[0]=0;
	    for(int i=1;i<=n;i++)
	    {
	        c[i]=inf;
	        for(int j=1;j<=i;j++)
	        {
	            if(c[j-1]!=inf && ls[j][i]!=inf &&c[j-1]+ls[j][i]<c[i])
	            {
	                c[i] = c[j-1]+ls[j][i];
	                p[i]=j;     //we will reach i from jth position
	            }
	        }
	    }
	    print(p,n);
	    cout<<endl;
	    
	}
	return 0;
}
