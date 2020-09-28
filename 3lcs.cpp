#include <iostream>
using namespace std;

int lcs(string a,string b, string c,int l1,int l2,int l3)
{
    int l[l1+1][l2+1][l3+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            for(int k=0;k<=l3;k++)
            {
                if(i==0||j==0||k==0)
                {
                    l[i][j][k] = 0;
                }
                else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
                {
                    l[i][j][k] = 1+l[i-1][j-1][k-1];
                }
                else
                {
                    l[i][j][k] = max(max(l[i-1][j][k],l[i][j-1][k]),l[i][j][k-1]);
                }
            }
        }
    }
    return l[l1][l2][l3];
}


int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int l1,l2,l3;
	    cin>>l1>>l2>>l3;
	    string a,b,c;
	    cin>>a>>b>>c;
	    cout<<lcs(a,b,c,l1,l2,l3)<<endl;
	}
	return 0;
}