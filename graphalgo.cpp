#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v;
	list<int> *adj;					//declares a list of type integers.

	void dfsUtil(int s, bool visited[]);
public:
	graph(int v);

	void addNode(int v,int n);

	void bfs(int s);

	void dfs(int s);
};

graph::graph(int v)
{
	this->v=v;
	adj = new list<int>[v];				//creates an array of type list of size V
}

void graph::addNode(int v,int n)
{
	adj[v].push_back(n);
}

void graph::bfs(int s)
{
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);
	list<int>::iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<"  ";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}

}

void graph::dfsUtil(int s, bool visited[])
{
	visited[s]=true;
	cout<<s<<"  ";
	list<int>::iterator i;

	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
		{
			dfsUtil(*i,visited);
		}
	}
}

void graph::dfs(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[v]=false;
	}
	dfsUtil(s,visited);
}

int main()
{
	graph g(4);
	g.addNode(0, 1);
	g.addNode(0, 2);
	g.addNode(1,2);
	g.addNode(2,0);
	g.addNode(2,3);
	g.addNode(3,3);

	cout<<"BFS traversal of the tree starting from vertex 2 is is "<<endl;
	g.bfs(2);
	cout<<"\n"<<"DFS traversal of the tree starting from vertex 2 is is "<<endl;
	g.dfs(2);
	return 0;
}
