#include<bits/stdc++.h>
using namespace std;

void printitems(int val[], int wt[],int w)
{
	int wt_s = sizeof(wt);
	//first row and first column will be zero so that we don't have to check if i==0 while comparing the values in dp because if we don't 
	// pit first row and column 0 then we will have to checkfor i==0 separately.
	int dp[wt_s+1][w+1];
	for(int i=0;i<=wt_s;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(j<wt[i-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
		}
	}
	for(int i=0;i<=wt_s;i++)
	{
		for(int j=0;j<=w;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[wt_s][w];
}
 
int main()
{
	int val[] = {1,4,5,7};
	int wt[] = {1,3,4,5};
	int W=7;
	printitems(val,wt,W);
	return 0;
}