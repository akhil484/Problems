#include<bits/stdc++.h>
using namespace std;
#define V 8
#define pb push_back



void DFS1(int i,vector<bool>& visited,stack<int>& mystack,unordered_map<int,vector<int>>& adj)
{
	visited[i]=true;
	for(int j: adj[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack,adj);

	mystack.push(i);
}

void reverse(unordered_map<int,vector<int>>& adj,unordered_map<int,vector<int>>& rev)
{
	for(int i=0;i<V;++i)
	{
		for(int j: adj[i])
			rev[j].pb(i);
	}
}

void DFS2(int i,vector<bool>& visited,unordered_map<int,vector<int>>& rev)
{
	cout<<i<<" ";
	visited[i] = true;
	for(int j: rev[i])
		if(!visited[j])
			DFS2(j,visited,rev);
}

void findSCCs(unordered_map<int,vector<int>>& adj,unordered_map<int,vector<int>>& rev)
{
	stack<int> mystack;

	vector<bool> visited(V,false);
	for(int i=0;i<V;++i)
		if(!visited[i])
			DFS1(i,visited,mystack,adj);

	reverse(adj,rev);

	for(int i=0;i<V;++i)
		visited[i] = false;

	cout<<"Strongly Connected Components are:\n";
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			DFS2(curr,visited,rev);
			cout<<"\n";
		}
	}
}

int main()
{
    unordered_map<int,vector<int>> adj,rev;
	adj[0].pb(1);
	adj[1].pb(2);
	adj[2].pb(0);
	adj[2].pb(3);
	adj[3].pb(4);
	adj[4].pb(5);
	adj[4].pb(7);
	adj[5].pb(6);
	adj[6].pb(4);
	adj[6].pb(7);

	findSCCs(adj,rev);
	return 0;
}

//TIME COMPLEXITY: O(V+E)
