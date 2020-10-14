/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		long long int n;
		cin>>n;
		long long int a[n];
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long int dp[n];
		memset(dp,0,sizeof(dp));
		dp[0]=a[0];
		dp[1]=max(a[0],a[1]);
		for(long long int i=2;i<n;i++)
		{
			dp[i] = max(dp[i],max(dp[i-1],dp[i-2]+a[i]));
		}
		long long int m=INT_MIN;
		for(long long int i=0;i<n;i++)
		{
			if(m<dp[i])
				m=dp[i];
		}
		cout<<"Case "<<t+1<<": "<<m<<"\n";
	}
}
