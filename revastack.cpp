#include<bits/stdc++.h>
using namespace std;
stack<int> s;

void stack_rev()
{
	if(s.empty()==true)
	{
		return;
	}
	int num = s.top();
	s.pop();
	stack_rev();
	s.push(num);
}

int main()
{
	for(int i=0;i<7;i++)
	{
		s.push(i);
	}
	stack_rev();
	while(s.empty()!=true)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

