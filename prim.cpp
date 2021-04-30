// #include<bits/stdc++.h>
// using namespace std;
// #define V 5

// int minkey(int key[], bool mstset[])
// {
// 	int min = INT_MAX,index=-1;
// 	for(int i=0;i<V;i++)
// 	{
// 		if(mstset[i]==false && key[i]<min)
// 		{
// 			min=key[i];
// 			index=i;
// 		}
// 	}
// 	return index;
// }

// void parentmst(int parent[], int graph[V][V])
// {
// 	cout<<"Edge \tWeight"<<"\n";
// 	for(int i=1;i<V;i++)
// 	{
// 		cout<<parent[i]<<"-"<<i<<"\t"<<graph[parent[i]][i]<<endl;
// 	}
// }


// void printMst(int graph[V][V])
// {
// 	int parent[V];
// 	int key[V];
// 	bool mstset[V];
// 	for(int i=0;i<V;i++)
// 	{
// 		key[i] = INT_MAX;
// 		mstset[i] = false;
// 	}
// 	key[0] = 0;					//starting element. It can be any element you want to start with and it is kept 0 so it get picked first
// 	parent[0] = -1;	
// 	for(int i=0;i<V-1;i++)
// 	{
// 		int u = minkey(key,mstset);
// 		mstset[u] = true;
// 		for(int v=0;v<V;v++)
// 		{
// 			if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v])
// 			{
// 				key[v] = graph[u][v];
// 				parent[v] = u;
// 			}
// 		}
// 	}
// 	parentmst(parent,graph);	
// }



// int main()
// {
// 	/* Let us create the following graph 
//         2 3 
//     (0)--(1)--(2) 
//     | / \ | 
//     6| 8/ \5 |7 
//     | / \ | 
//     (3)-------(4) 
//             9     */
//     int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
//                         { 2, 0, 3, 8, 5 }, 
//                         { 0, 3, 0, 0, 7 }, 
//                         { 6, 8, 0, 0, 9 }, 
//                         { 0, 5, 7, 9, 0 } };
//     printMst(graph);
//     return 0;
// }

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

void parentmst(int parent[], unordered_map<int,vector<pair<int,int>>>& adj,int key[])
{
	cout<<"Edge \tWeight"<<"\n";
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"\t"<<key[i]<<endl;
	}
}


void printMst(unordered_map<int,vector<pair<int,int>>>& adj)
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
		for(auto v:adj[u])
		{
		    int node=v.first;
		    int we=v.second;
			if(mstset[node]==false && we<key[node])
			{
				key[node] = we;
				parent[node] = u;
			}
		}
	}
	parentmst(parent,adj,key);	
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
        //   unordered_map<int,pair<int,int>> adj;
           unordered_map<int,vector<pair<int,int>>> adj;
            adj[0].push_back(make_pair(1,2));
            adj[0].push_back(make_pair(3,6));
            adj[1].push_back(make_pair(0,2));
            adj[1].push_back(make_pair(2,3));
            adj[1].push_back(make_pair(3,8));
            adj[1].push_back(make_pair(4,5));
            adj[2].push_back(make_pair(1,3));
            adj[2].push_back(make_pair(4,7));
            adj[3].push_back(make_pair(0,6));
            adj[3].push_back(make_pair(1,8));
            adj[3].push_back(make_pair(4,9));
            adj[4].push_back(make_pair(1,5));
            adj[4].push_back(make_pair(2,7));
            adj[4].push_back(make_pair(3,9));
    // int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
    //                     { 2, 0, 3, 8, 5 }, 
    //                     { 0, 3, 0, 0, 7 }, 
    //                     { 6, 8, 0, 0, 9 }, 
    //                     { 0, 5, 7, 9, 0 } };
    printMst(adj);
    return 0;
}
