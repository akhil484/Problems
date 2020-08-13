#include<iostream>
#include<stack>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int a[n+1];
	a[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	stack<int> s;
	int right[n+1],left[n+1];
	right[0] = left[0] = 0;
	for(int i=1;i<=n;i++)
	{
		if(s.empty())
		{
			s.push(i);
			continue;
		}
		while(!s.empty() && a[i]>a[s.top()])
		{
			right[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		right[s.top()] = 0;
		s.pop();
	}
	for(int i=n;i>=1;i--)
	{
		if(s.empty())
		{
			s.push(i);
			continue;
		}
		while(!s.empty()&& a[i]>a[s.top()])
		{
			left[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		left[s.top()] = 0;
		s.pop();
	}
	int ans = -1;
	for(int i=1;i<=n;i++)
	{
		ans = max(ans,(left[i] * right[i]));
	}
	cout<<ans;
	return 0;

}