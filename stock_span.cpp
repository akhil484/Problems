#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int span[n];
	stack<int> s;
	s.push(0);
	span[0] = 1;
	for(int i=0;i<n;i++)
	{
		while(!s.empty()&&a[s.top()]<=a[i])
			s.pop();
		span[i] = (s.empty())?(i+1):(i-s.top());
		s.push(i);
	}
	for(int i=0;i<n;i++)
	{
		cout<<span[i]<<" ";
	}
	return 0;
}