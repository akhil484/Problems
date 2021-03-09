/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int ta[100001],td[100001];
int cnt;
vector<int> v[100001];
bool visited[100001];
void dfs(int src)
{
    visited[src]=true;
    cnt++;
    ta[src]=cnt;
    for(int i=0;i<v[src].size();i++)
    {
        if(!visited[v[src][i]])
        {
            dfs(v[src][i]);
            cnt++;
        }
    }
    cnt++;
    td[src]=cnt;

}
int main()
{
    
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);
    int n;
    cin>>n;
    
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            dfs(i);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if (a == 1) swap(c, b);
		if (ta[b] <= ta[c] && td[c] <= td[b]) printf("YES\n");
		else printf("NO\n");
    }
}
