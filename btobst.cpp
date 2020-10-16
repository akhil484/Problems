#include<bits/stdc++.h>
using namespace std;

void inorder(int a[],int n, vector<int> &v,int index)
{
	if(index>=n)
		return;
	inorder(a,n,v,(2*index)+1);
	v.push_back(a[index]);
	inorder(a,n,v,(2*index)+2);
}

int minswaps(vector<int> &v)
{
	vector<pair<int,int>> p(v.size());
	int n=v.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		p[i].first=v[i];
		p[i].second=i;
	}
	sort(p.begin(),p.end());
	vector<bool> vis(n,false);
	for(int i=0;i<n;i++)
	{
		if(vis[i] || p[i].second==i)
			continue;
		else
		{
			int cycle_size=0;
			int j=i;
			while(!vis[j])
			{
				vis[j]=1;
				j=p[j].second;
				cycle_size++;
			}
			if(cycle_size>0)
				ans+=(cycle_size-1);
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> v;
	inorder(a,n,v,0);
	int swap_count=minswaps(v);
	cout<<swap_count<<"\n";
}