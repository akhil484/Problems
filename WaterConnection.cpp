#include <bits/stdc++.h>
using namespace std;

struct record{
    int a;
    int b;
    int d;
};
int s_index[50];
int e_index[50];
int pipe[50];
vector<int> x;
vector<int> y;
vector<int> z;
int ans;
int dfs(int w)
{
    if(s_index[w]==0)
    {
        return w;
    }
    if(pipe[w]<ans)
        ans=pipe[w];
    return dfs(s_index[w]);
}
void solve(record re[],int n, int p)
{
    for(int i=0;i<p;i++)
    {
        s_index[re[i].a] = re[i].b;
        pipe[re[i].a] = re[i].d;
        e_index[re[i].b] = re[i].a;
    }
    x.clear();
    y.clear();
    z.clear();
    for(int i=1;i<=n;i++)
    {
        if(e_index[i]==0 && s_index[i])
        {
            ans=100000;
            int w=dfs(i);
            x.push_back(i);
            y.push_back(w);
            z.push_back(ans);
        }
    }
    cout<<x.size()<<"\n";
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
    }
    
}

int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n,p;
	    cin>>n>>p;
	    struct record r[p];
	    for(int i=0;i<p;i++)
	    {
	        cin>>r[i].a>>r[i].b>>r[i].d;
	    }
	    memset(s_index,0,sizeof(s_index));
	    memset(e_index,0,sizeof(e_index));
	    memset(pipe,0,sizeof(pipe));
	    
	    solve(r,n,p);
	}
	return 0;
}
