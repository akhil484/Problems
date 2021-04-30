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

// void parentmst(int parent[], unordered_map<int,vector<pair<int,int>>>& adj,int key[])
// {
// 	cout<<"Edge \tWeight"<<"\n";
// 	for(int i=1;i<V;i++)
// 	{
// 		cout<<parent[i]<<"-"<<i<<"\t"<<key[i]<<endl;
// 	}
// }


// void printMst(unordered_map<int,vector<pair<int,int>>>& adj)
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
// 		for(auto v:adj[u])
// 		{
// 		    int node=v.first;
// 		    int we=v.second;
// 			if(mstset[node]==false && we<key[node])
// 			{
// 				key[node] = we;
// 				parent[node] = u;
// 			}
// 		}
// 	}
// 	parentmst(parent,adj,key);	
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
//         //   unordered_map<int,pair<int,int>> adj;
//            unordered_map<int,vector<pair<int,int>>> adj;
//             adj[0].push_back(make_pair(1,2));
//             adj[0].push_back(make_pair(3,6));
//             adj[1].push_back(make_pair(0,2));
//             adj[1].push_back(make_pair(2,3));
//             adj[1].push_back(make_pair(3,8));
//             adj[1].push_back(make_pair(4,5));
//             adj[2].push_back(make_pair(1,3));
//             adj[2].push_back(make_pair(4,7));
//             adj[3].push_back(make_pair(0,6));
//             adj[3].push_back(make_pair(1,8));
//             adj[3].push_back(make_pair(4,9));
//             adj[4].push_back(make_pair(1,5));
//             adj[4].push_back(make_pair(2,7));
//             adj[4].push_back(make_pair(3,9));
//     // int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
//     //                     { 2, 0, 3, 8, 5 }, 
//     //                     { 0, 3, 0, 0, 7 }, 
//     //                     { 6, 8, 0, 0, 9 }, 
//     //                     { 0, 5, 7, 9, 0 } };
//     printMst(adj);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define V 5
# define INF 0x3f3f3f3f


void printMst(unordered_map<int,vector<pair<int,int>>>& adj)
{priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);
 
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        inMST[u] = true;  // Include vertex in MST
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (auto i:adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (i).first;
            int weight = (i).second;
 
            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    // Print edges of MST using parent array
    cout<<"Edge \tWeight"<<"\n";
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"\t"<<key[i]<<endl;
	}
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
