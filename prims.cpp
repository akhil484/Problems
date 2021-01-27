#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

class Graph
{
	int v;
	list< pair<int,int> > *adj;

public:
	Graph(int v);
	void addEdge(int u, int w, int wt);
	void primMST();
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<iPair> [v];
}

void Graph::addEdge(int u,int w,int wt)
{
	adj[u].push_back(make_pair(w,wt));
	adj[w].push_back(make_pair(u,wt));
}

void Graph::primMST()
{

	priority_queue<iPair,vector<iPair>, greater<iPair> > pq;
	int src=0;
	vector<int> key(v,INT_MAX);
	vector<int> parent(v,-1);
	vector<bool> inMST(v,false);
	pq.push(make_pair(0,src));
	key[src]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		inMST[u]=true;
		list< pair<int,int> > ::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			int ver=(*i).first;
			int weight=(*i).second;
			if(inMST[ver]==false && key[ver]>weight)
			{
				key[ver]=weight;
				pq.push(make_pair(key[ver],ver));
				parent[ver]=u;
			}
		}
	}
	for(int i=0;i<v;i++)
	{
		cout<<parent[i]<<" "<<i<<endl;
	}
}

int main()
{
	int v=6;
	Graph g(v);
	g.addEdge(0, 1, 4); 
    g.addEdge(0, 2, 6); 
    g.addEdge(1, 2, 6); 
    g.addEdge(1, 4, 4); 
    g.addEdge(1, 3, 3); 
    g.addEdge(2, 3, 1);  
    g.addEdge(3, 4, 2); 
    g.addEdge(3, 5, 3); 
    g.addEdge(4, 5, 5);  
    g.primMST(); 
  
    return 0; 
}