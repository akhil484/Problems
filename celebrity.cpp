#include<iostream>
#include<stack>
using namespace std;

int MATRIX[4][4] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 

int knows(int a,int b)
{
	return MATRIX[a][b];
}

int checkcelebrity(int n)
{
	stack<int> s;
	int id;
	for(int i=0;i<n;i++)
	{
		s.push(i);
	}
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	while(s.size()>1)
	{
		if(knows(a,b))
		{
			a=s.top();
			s.pop();
		}
		else
		{
			b = s.top();
			s.pop();
		}
	}

	int c = s.top();
	s.pop();
	if(knows(c,a))
		c=a;
	if(knows(c,b))
		c=b;

	for(int i=0;i<n;i++)
	{
		if(i!=c && (knows(c,i) || !knows(i,c)))
			return -1;
	}
	return c;
}

int main()
{
	int n;
	cin>>n;
	int id = checkcelebrity(n);
	if(id==-1)
		cout<<"No Celebrity"<<endl;
	else
	{
		cout<<"Celebrity Id "<<id<<endl;
	}
	return 0;
}