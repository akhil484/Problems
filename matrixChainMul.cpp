#include<bits/stdc++.h>
using namespace std;

int findMul(int a[], int n)
{
	int dp[n-1][n-1];
	int q=0;
	//Diagonal points
	for(int i=0;i<n;i++)
		dp[i][i]=0;
	//when gap is 1
	for(int i=0;i<n-2;i++)
		dp[i][i+1] = a[i]*a[i+1]*a[i+2];
	for(int l=2;l<n-1;l++)
	{
		for(int i=0;i<n-1;i++)
		{
			int j=i+l;
			//int q=0;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++)
			{
				//matrix at i will have dimension of a[i]xa[i+1]
				//To multiply the matrix of dp[i][k] and dp[k+1][j] we need to add the number of operations in that.
				//which are a[i]*a[k+1]*a[j]
				//In this question we need dp[0][last_index]
				q=dp[i][k] + dp[k+1][j] + a[i]*a[k+1]*a[j+1];
				if(q<dp[i][j])
					dp[i][j] = q;
			}
		}
	}
	int dp_len=n-1;
	return dp[0][dp_len-1];
}


int main()
{

	int a[]={4,2,3,5,3};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<findMul(a,n);

}