#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	void topsortUtil(int i, bool visited[], stack<int> &s);

public:
	graph(int v);
	void addedge(int u, int w);
	void topsort();
};

graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];				//An array of type list‹int› will be created and its size will be v
}

void graph::addedge(int u, int w)
{
	adj[u].push_back(w);
}

void graph::topsortUtil(int i, bool visited[], stack<int> &s)
{
	visited[i] = true;
	list<int>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++)
	{
		if(!visited[*it])
			topsortUtil(*it,visited,s);
	}
	s.push(i);
}

void graph::topsort()
{
	stack<int> s;
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i] = false;
	}
	for(int i=0;i<v;i++)
		if(visited[i] == false)
			topsortUtil(i,visited,s);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

}

int main()
{
	graph g(6);
	g.addedge(5, 2); 
    g.addedge(5, 0); 
    g.addedge(4, 0); 
    g.addedge(4, 1); 
    g.addedge(2, 3); 
    g.addedge(3, 1);
    cout<<"Topological Sort of a Directed acyclic graph is:"<<"\n";
    g.topsort();
    return 0; 
}
