#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		int n;
		cin>>n;
		int a[n];
		int cnt[n+1];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		int ans = 0;
		for(int s=2;s<=2*n;s++)
		{
			int cur=0;
			for(int i=1;i<(s+1)/2;i++)
			{
				if(s-i>n)
					continue;
				cur +=min(cnt[i],cnt[s-i]);
			}
			if(s%2==0)
				cur +=cnt[s/2]/2;
			ans = max(ans,cur);
		}
		cout<<ans<<"\n";
	}
	return 0;

}