#include <iostream>
using namespace std;

bool check(int a[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2!=0)
        return false;
    bool part[sum/2 + 1][n+1];
    for(int i=0;i<=n;i++)
        part[0][i] = true;
    for(int i=1;i<=sum/2;i++)
    {
        part[i][0] = false;
    }
    for(int i=1;i<=sum/2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            part[i][j] = part[i][j-1];
            if(i>=a[j-1])
            {
                part[i][j] = part[i][j] || part[i-a[j-1]][j-1];
            }
        }
    }
    return part[sum/2][n];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    bool ans = check(a,n);
	    if(ans==true)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}