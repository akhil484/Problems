// #include<bits/stdc++.h> 
// using namespace std; 
// # define INF 0x3f3f3f3f 
  
// // This class represents a directed graph using  
// // adjacency list representation 
// class Graph 
// { 
//     int V;    // No. of vertices 
  
//     // In a weighted graph, we need to store vertex  
//     // and weight pair for every edge 
//     list< pair<int, int> > *adj; 
  
// public: 
//     Graph(int V);  // Constructor 
  
//     // function to add an edge to graph 
//     void addEdge(int u, int v, int w); 
  
//     // prints shortest path from s 
//     void shortestPath(int s); 
// }; 
  
// // Allocates memory for adjacency list 
// Graph::Graph(int V) 
// { 
//     this->V = V; 
//     adj = new list< pair<int, int> >[V]; 
// } 
  
// void Graph::addEdge(int u, int v, int w) 
// { 
//     adj[u].push_back(make_pair(v, w)); 
//     adj[v].push_back(make_pair(u, w)); 
// } 

// void printPath(vector<int> &parent, int j) 
// { 
      
//     // Base Case : If j is source 
//     if (parent[j] == - 1) 
//         return; 
  
//     printPath(parent, parent[j]); 
  
//     cout<<" "<<j; 
// } 
  

// void printSolution(vector<int> &dist, int V,  
//                       vector<int> &parent) 
// { 
//     int src = 0; 
//     cout<<"Vertex"<<"       "<<"Distance"<<"           "<<"Path"; 
//     for (int i = 1; i < V; i++) 
//     { 
//         cout<<"\n"<<src<<" -> "<<i<<"\t\t "<<dist[i]<<"\t\t"<<src; 
//         printPath(parent, i); 
//     } 
// } 

// // Prints shortest paths from src to all other vertices 
// void Graph::shortestPath(int src) 
// { 
//     // Create a set to store vertices that are being 
//     // prerocessed 
//     set< pair<int,int> >sets;
//     vector<int> dist(V,INF);
//     vector<int> parent(V,-1);
//     sets.insert(make_pair(0,src));
//     dist[src] = 0;
//     while(!sets.empty())
//     {
//         pair<int,int> tmp = *(sets.begin());
//         sets.erase(sets.begin());
//         int u=tmp.second;
//         list<pair<int,int> >::iterator i;
//         for(i=adj[u].begin();i!=adj[u].end();i++)
//         {
//             int v = (*i).first;
//             int weight = (*i).second;
//             if(dist[v]>dist[u]+weight)
//             {
//                 if(dist[v]!=INF)
//                     sets.erase(sets.find(make_pair(dist[v],v)));
//                 dist[v] = dist[u]+weight;
//                 parent[v] = u;
//                 sets.insert(make_pair(dist[v],v));
//             }
//         }
//     }
//     printSolution(dist,V,parent);
// } 
  
// // Driver program to test methods of graph class 
// int main() 
// { 
//     // create the graph given in above fugure 
//     int V = 9; 
//     Graph g(V); 
  
//     //  making above shown graph 
//     g.addEdge(0, 1, 4); 
//     g.addEdge(0, 7, 8); 
//     g.addEdge(1, 2, 8); 
//     g.addEdge(1, 7, 11); 
//     g.addEdge(2, 3, 7); 
//     g.addEdge(2, 8, 2); 
//     g.addEdge(2, 5, 4); 
//     g.addEdge(3, 4, 9); 
//     g.addEdge(3, 5, 14); 
//     g.addEdge(4, 5, 10); 
//     g.addEdge(5, 6, 2); 
//     g.addEdge(6, 7, 1); 
//     g.addEdge(6, 8, 6); 
//     g.addEdge(7, 8, 7); 
  
//     g.shortestPath(0); 
  
//     return 0; 
// } 


#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
  
// This class represents a directed graph using  
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // In a weighted graph, we need to store vertex  
    // and weight pair for every edge 
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v, int w); 
  
    // prints shortest path from s 
    void shortestPath(int s); 
}; 
  
// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list< pair<int, int> >[V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 

void printPath(vector<int> &parent, int j) 
{ 
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j]); 
  
    cout<<" "<<j; 
} 
  

void printSolution(vector<int> &dist, int V,  
                      vector<int> &parent) 
{ 
    int src = 0; 
    cout<<"Vertex"<<"       "<<"Distance"<<"           "<<"Path"; 
    for (int i = 1; i < V; i++) 
    { 
        cout<<"\n"<<src<<" -> "<<i<<"\t\t "<<dist[i]<<"\t\t"<<src; 
        printPath(parent, i); 
    } 
} 

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
    // Create a set to store vertices that are being 
    // prerocessed 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // set< pair<int,int> >sets;
    vector<int> dist(V,INF);
    vector<int> parent(V,-1);
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(!pq.empty())
    {
        pair<int,int> tmp = pq.top();
        pq.pop();
        int u=tmp.second;
        list<pair<int,int> >::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if(dist[v]>dist[u]+weight)
            {
                // if(dist[v]!=INF)
                //     sets.erase(sets.find(make_pair(dist[v],v)));
                dist[v] = dist[u]+weight;
                parent[v] = u;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    printSolution(dist,V,parent);
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
  
    return 0; 
} 
