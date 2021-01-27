#include<bits/stdc++.h>
using namespace std;

struct node
{
	int parent;
	int rank;
};
vector<node> dsuf;

int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);
}

void union_op(int fromp, int topp)
{
	if(dsuf[fromp].rank>dsuf[topp].rank)
	{
		dsuf[topp].parent=fromp;
	}
	else if(dsuf[fromp].rank<dsuf[topp].rank)
	{
		dsuf[fromp].parent=topp;
	}
	else
	{
		dsuf[fromp].parent=topp;
		dsuf[topp].rank+=1;
	}
}

bool isCyclic(vector<pair<int,int> >& edge_list)
{
	for(auto p:edge_list)
	{
		int fromp=find(p.first);
		int topp=find(p.second);
		if(fromp==topp)
			return true;
		union_op(fromp,topp);
	}
	return false;
}

int main()
{
	int E;
	int V;
	cin>>E>>V;
	dsuf.resize(V);
	for(int i=0;i<V;i++)
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}
	vector<pair<int,int> > edge_list;
	for(int i=0;i<E;i++)
	{
		int from,to;
		cin>>from>>to;
		edge_list.push_back(make_pair(from,to));
	}
	if(isCyclic(edge_list))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}