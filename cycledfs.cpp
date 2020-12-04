#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	bool isCyclicUtil(int n, bool visited[], bool *recStack);
public:
	graph(int v);
	void addEdge(int n, int w);
	bool isCyclic();
};

graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void graph::addEdge(int n, int w)
{
	adj[n].push_back(w);
}

bool graph::isCyclic()
{
	bool *visited = new bool[v];
	bool *recStack = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	for(int i=0;i<v;i++)
	{
		if(isCyclicUtil(i,visited,recStack));
			return true;
	}
	return false;
}

bool graph::isCyclicUtil(int n, bool visited[], bool *recStack)
{
	if(visited[n]==false)
	{
		visited[n] = true;
		recStack[n] = true;
		list<int>::iterator it;
		for(it=adj[n].begin();it!=adj[n].end();it++)
		{
			if(!visited[*it] && isCyclicUtil(*it,visited,recStack))
				return true;
			else if(recStack[*it])
				return true;
		}
	}
	recStack[n] = false;
	return false;
}

int main()
{
	graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
}