#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll r1, ll c1, ll r2, ll c2)
{
	return ((r1+c1==r2+c2) || (r1-c1==r2-c2) || (abs(r1-r2)+abs(c1-c2))<=3);
}

// void swap(ll *a, ll *b)
// {
// 	a=a+b;
// 	b=a-b;
// 	a=a-b;
// }

void solve(ll r1, ll c1, ll r2, ll c2)
{
	if(r1>r2)
	{
		swap(r1,r2);
		swap(c1,c2);
	}
	if(r1==r2 && c1==c2)
	{
		cout<<0;
		return;
	}
	if(check(r1,c1,r2,c2))
	{
		cout<<1;
		return;
	}
	if((r1+c1)%2==(r2+c2)%2)
	{
		cout<<2;
		return;
	}

	for(ll i=-2;i<=2;i++)
	{
		for(ll j=-2;j<=2;j++)
		{
			ll p=r2+i;
			ll q=c2+j;
			if(check(r1,c1,p,q))
			{
				cout<<2;
				return;
			}
		}
	}
	if(check(r1,c1,r2-3,c2) || check(r1,c1,r2+3,c2) || check(r1,c1,r2,c2-3) || check(r1,c1,r2,c2+3))
	{
		cout<<2;
		return;
	}
	cout<<3;
}

int main()
{
	ll r1,c1,r2,c2;
	cin>>r1>>c1;
	cin>>r2>>c2;
	solve(r1,c1,r2,c2);
	return 0;
}