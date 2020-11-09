#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
		int n;
		cin>>n;
		int total=0;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			total+=a[i];
		}
		if(total%2==1)
			cout<<-1<<endl;
		else
		{
			int dp[2002]={0};
			int change[2002]={0};
			dp[0] = 1;  //I can make sum of 0 with an empty set.
			change[0] = 0;
			for(int i=1;i<2002;i++)
			{
				change[i] = INT_MAX:
			}
			dp[1001] = 1; 
			change[1001] = 0;
			for(int i=0;i<n;i++)
			{
				if(a[i]>0)
				{
					for(int j=1000;j>=a[i];j--)
					{
						if(dp[j-a[i]]!=0)
						{
							dp[j]=1;
							change[j] = min(change[j],1+change[j-a[i]]);
						}
					}
				}
				else
				{
					for(int j=2001;j>=1001+abs(a[i]);j--)
					{
						if(dp[j-abs(a[i])]!=0)
						{
							dp[j] = 1;
							change[j] = min(change[j],change[j-abs(a[i])]+1);
						}
					}
				}
			}
			total=total/2;
			if(total<0)
			{
				total=1001+abs(total);
				if(dp[total]==0)
					cout<<-1<<endl;
				else
				{
					cout<<change[total]<<endl;
				}
			}
			else
			{
				if(dp[total]==0)
					cout<<-1<<endl;
				else
					cout<<change[total]<<endl;
			}
			
		}
	}
	return 0;
}
