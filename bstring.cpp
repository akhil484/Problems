#include<bits/stdc++.h>
using namespace std;


int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	int n;
	string s;
	cin>>n>>s;
	vector<int> ans(n);
	vector<int> p0,p1;
	//vector<int> p1;
	for(int i=0;i<n;i++)
	{
		int newpos = p1.size() + p0.size();
		if(s[i]=='0')
		{
			if(p1.empty())
				p0.push_back(newpos);
			else
			{
				newpos = p1.back();
				p1.pop_back();
				p0.push_back(newpos);
			}
		}
		else
		{
			if(p0.empty())
				p1.push_back(newpos);
			else
			{
				newpos = p0.back();
				p0.pop_back();
				p1.push_back(newpos);
			}
		}
		ans[i] = newpos;
		
	}
	cout<<p0.size()+p1.size()<<endl;
		for(int i=0;i<n;i++)
			cout<<ans[i]+1<<" ";
		cout<<"\n";
	} 
	return 0;
}