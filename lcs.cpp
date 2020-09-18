#include <iostream>
using namespace std;

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
 

int lcs(string x, string y, int l1,int l2)
{
    int l[l1+1][l2+1];
    for(int i=0;i<=l1;i++)                     //It will build in bottom up fashion
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0||j==0)                     //l[i][j] will give the lcs upto x[0...i-1] and y[0..j-1]. That's why we will traverse upto l1 and l2 as at l1 and l2 it will compare last characters i.e. x[l1-1] and y[l2-1]
                l[i][j] = 0;
            else if(x[i-1]==y[j-1])
                l[i][j] = 1+l[i-1][j-1];
            else
                l[i][j] = max(l[i][j-1],l[i-1][j]);
        }
    }
    return l[l1][l2];
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