#include<bits/stdc++.h>
using namespace std;
#define V 5

int minkey(int key[], bool mstset[])
{
	int min = INT_MAX,index=-1;
	for(int i=0;i<V;i++)
	{
		if(mstset[i]==false && key[i]<min)
		{
			min=key[i];
			index=i;
		}
	}
	return index;
}

void parentmst(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight"<<"\n";
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"\t"<<graph[parent[i]][i]<<endl;
	}
}


void printMst(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstset[V];
	for(int i=0;i<V;i++)
	{
		key[i] = INT_MAX;
		mstset[i] = false;
	}
	key[0] = 0;					//starting element. It can be any element you want to start with and it is kept 0 so it get picked first
	parent[0] = -1;	
	for(int i=0;i<V-1;i++)
	{
		int u = minkey(key,mstset);
		mstset[u] = true;
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v])
			{
				key[v] = graph[u][v];
				parent[v] = u;
			}
		}
	}
	parentmst(parent,graph);	
}



int main()
{
	/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } };
    printMst(graph);
    return 0;
}