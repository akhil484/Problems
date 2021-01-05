#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > maze;
vector<vector<int> > sol;
int n;

int is_valid(int i, int j)
{
	if(i>=0 && j>=0 && i<n && j<n && maze[i][j]==1)
	{
		return 1;
	}
	return 0;
}

int rat_maze(int i,int j)
{
	if(i==n-1 && j==n-1 && maze[i][j]==1)
	{
		sol[i][j] = 1;
		
		return 1;
	}

	if(is_valid(i,j))
	{
		sol[i][j] = 1;
		
		if(rat_maze(i+1,j)==1)
			return 1;

		if(rat_maze(i,j+1)==1)
			return 1;
		sol[i][j] = 0;
		
		return 0;
	}
	return 0;
}

void print_solution()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<sol[i][j]<<" ";
			
		}
		cout<<"\n";
	}
}
int main()
{
	int a,res;
	cout<<"Enter the value of n"<<"\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		vector<int> r;
		for(int j=0;j<n;j++)
		{
			cin>>a;
			r.push_back(a);
		}
		maze.push_back(r);
	}

	for(int i=0;i<n;i++)
	{
		vector<int> zz;
		for(int j=0;j<n;j++)
		{
			zz.push_back(0);
		}
		sol.push_back(zz);
	}
	res=rat_maze(0,0);
	cout<<endl;
	if(res==0)
		cout<<"Solution does not exist"<<"\n";
	else
	{
		cout<<"Output"<<endl;
		print_solution();
	}
}

















void mazeHelp(int m[MAX][MAX], int n, int i, int j, vector<string> &pp, string path)
{
    if(i>=n || i<0 || j>=n || j<0 || m[i][j]!=1)
        return;
    if(i==n-1 && j==n-1)
    {
        pp.push_back(path);
        return;
    }
    
    m[i][j]=-1;
    mazeHelp(m,n,i+1,j,pp,path+'D');
    mazeHelp(m,n,i,j+1,pp,path+'R');
    mazeHelp(m,n,i,j-1,pp,path+'L');
    mazeHelp(m,n,i-1,j,pp,path+'U');
    m[i][j]=1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    
    vector<string> pp;
    string s="";
    mazeHelp(m,n,0,0,pp,s);
    sort(pp.begin(),pp.end());
    return pp;
}
