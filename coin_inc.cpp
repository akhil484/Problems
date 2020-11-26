#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	vector<vector<vector<long double> > > dp (101,vector<vector<long double> >(101,vector <long double>(101)));
	for(int i=100;i>=0;i--)
	{
		for(int j=100;j>=0;j--)
		{
			for(int k=100;k>=0;k--)
			{
				if(i==100 || j==100 || k==100)
				{
					dp[i][j][k] = 0;
				}
				else if(i==0 && j==0 && k==0)
				{
					break;
				}
				else
				{
					ld cnt = i+j+k;
					dp[i][j][k] = 1 + i/cnt * dp[i+1][j][k] + j/cnt * dp[i][j+1][k] + k/cnt * dp[i][j][k+1];	
				}
			}
		}
	} 
	cout<<dp[a][b][c];
	return 0;
}