#include <iostream>
using namespace std;

 
 

int lcs(string x, string y, int l1,int l2)
{
    bool b;
    int l[2][l2+1];
    for(int i=0;i<=l1;i++)
    {
        b = i&1;
        for(int j=0;j<=l2;j++)
        {
            
            if(i==0||j==0)
                l[b][j] = 0;
            else if(x[i-1]==y[j-1])
                l[b][j] = 1+l[1-b][j-1];
            else
                l[b][j] = max(l[b][j-1],l[1-b][j]);
        }
    }
    return l[b][l2];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int l1,l2;
	    cin>>l1>>l2;
	    string st1,st2;
	    cin>>st1>>st2;
	    cout<<lcs(st1,st2,l1,l2)<<endl;
	}
	return 0;
}