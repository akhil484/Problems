// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicUtil(int v,bool visited[], int parent,vector<int> g[])
{
    visited[v] = true;
    vector<int>::iterator it;
    for(it=g[v].begin();it!=g[v].end();it++)
    {
        if(!visited[*it])
        {
            if(isCyclicUtil(*it,visited,v,g))
                return true;
        }
        else if(*it!=parent)
                return true;
    }
    return false;
}


bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   
   bool *visited = new bool[V];
   for(int i=0;i<V;i++)
    {visited[i] = false;
}

for(int i=0;i<V;i++)
{
    if(!visited[i])
    {
        if(isCyclicUtil(i,visited,-1,g))
            return true;
    }
}
   return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
