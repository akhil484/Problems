#include<bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
	return (a>b)?b:a;
}


int perm1(int n,int k)
{
	int p=1;
	for(int i=0;i<k;i++)
		p*=n-i;
	return p;
}

int perm2(int n,int k)
{
	int p[n+1];
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=i*p[i-1];
	}
	return p[n]/p[n-k];
}
int main()
{
	int n,k;
	cin>>n>>k;
	// int c[n+1][k+1];
	// cout<<"Fdsa";
	// for(int i=0;i<=n;i++)
	// {
	// 	cout<<"inside i";
	// 	for(int j=0;j<=min(k,i);j++)
	// 	{
	// 		cout<<"inside j";
	// 		if(j=0)
	// 			c[i][j]=1;
	// 		else
	// 			c[i][j]=c[i-1][j]+(c[i-1][j-1] * j);
	// 		c[i][j + 1] = 0;
	// 	}
	// }
	// cout<<c[n][k];

	cout<<perm2(n,k);
	return 0;
}