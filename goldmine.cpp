#include <bits/stdc++.h>
using namespace std;

int findallgold(int *gold,int n,int m)
{
    
    int table[n][m];
    memset(table,0,sizeof(table));
    for(int col=m-1;col>=0;col--)
    {
        for(int row=0;row<n;row++)
        {
            int right=(col==m-1)?0:table[row][col+1];
            int rightup=(row==0||col==m-1)?0:table[row-1][col+1];
            int right_down=(row==n-1||col==m-1)?0:table[row+1][col+1];
            table[row][col]=*(gold+row*m+col)+max(right,max(rightup,right_down));
            
        }
    }
    int max_res=table[0][0];
    for(int i=1;i<n;i++)
    {
        if(table[i][0]>max_res)
        {
            max_res=table[i][0];
        }
    }
    return max_res;
}

int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n,m;
	    cin>>n>>m;
	    int gold[n][m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>gold[i][j];
	        }
	    }
	    int max_gold=findallgold(&gold[0][0],n,m);
	    cout<<max_gold<<endl;
	}
	return 0;
}