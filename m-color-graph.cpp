// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
bool isSafe(bool graph[101][101], int V, int v, int rang, int color[]) {
    // your code here
    
    for(int i=0;i<V;i++){
        if(graph[v][i] == true && color[i] == rang)
            return false;
    }
    return true;
}

bool check(bool graph[101][101], int m, int V, int v, int color[])
{
    if(v==V)
        return true;
    for(int i=1;i<=m;i++)
    {
        if(isSafe(graph,V,v,i,color))
        {
            color[v]=i;
            if(check(graph,m,V,v+1,color))
                return true;
            color[v]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V){
    int color[V]={0};
    return check(graph,m,V,0,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
