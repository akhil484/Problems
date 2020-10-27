#include<bits/stdc++.h>
using namespace std;

void unbound(int val[], int wt[], int w, int n)
{
	int dp[w+1];
	dp[0] = 0;
	for(int i=1;i<=w;i++)
	{
		int max = 0;
		for(int j=0;j<n;j++)
		{
			if(wt[j]<=i)
			{
				int rbc = i-wt[j];
				int tbv = val[j] + dp[rbc];
				if(max<tbv)
					max=tbv;
			}
		}
		dp[i] = max;
	}
	cout<<dp[w];
}

int main()
{
	int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};

	unbound(val,wt,W,3);
	return 0;
}