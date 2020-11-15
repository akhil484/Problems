#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
		int n,ans=0;
		cin>>n;
		int b[n];
		// unordered_map<int, int> m;
		unordered_map<int, int> m;
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			m[b[i]]++;
			if(m[b[i]]>1)
				ans=1;
		}
		if(ans==0)
			cout<<"NO"<<"\n";
		else
			cout<<"YES"<<"\n";
	}
}