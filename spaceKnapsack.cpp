#include<bits/stdc++.h>
using namespace std;

void printitems(int val[], int wt[],int w)
{
	int wt_s = 3;
	int dp[2][w+1];
	memset(dp,0,sizeof(dp));
	int i=0;
	while(i<wt_s)
	{
		int j=0;
		if(i%2!=0)
		{
			while(++j<=w)		//we have already put 0 in first row and column so j will start from 1
			{
				if(wt[i]<=j)
					dp[1][j] = max(dp[0][j],val[i]+dp[0][j-wt[i]]);
				else
					dp[1][j] = dp[0][j];
			}
		}
		else
		{
			while(++j<=w)
			{
				if(wt[i]<=j)
					dp[0][j] = max(dp[1][j],val[i]+dp[1][j-wt[i]]);
				else
					dp[0][j] = dp[1][j];
			}
		}
		i++;
	}
	if(wt_s%2==0)
	{
		cout<<dp[1][w]<<endl;
	}
	else
	{
		cout<<dp[0][w]<<endl;
	}
}
 
int main()
{
	int val[] = {7, 8, 4};
	int wt[] = {3, 8, 6};
	int W=10;
	printitems(val,wt,W);
	return 0;
}