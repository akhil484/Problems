#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],res[n];
	memset(res,0,n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max_num=a[0];
	for(int i=1;i<n;i++)
	{
		max_num=max(max_num,a[i]);
	}
	int *freq_arr = new int[max_num+1]();
	for(int i=0;i<n;i++)
	{
		freq_arr[a[i]]++;
	}
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		if(s.empty())
			s.push(i);
		else
		{
			while(!s.empty() && freq_arr[a[i]]>freq_arr[a[s.top()]])
			{
				res[s.top()]=a[i];
				s.pop();
			}
			s.push(i);
		}
	}
	while(!s.empty())
	{
		res[s.top()]=-1;
		s.pop();
	}
	// for(int i=0;i<n;i++)
	// {
	// 	if(res[i]==0)
	// 		res[i]=-1;
	// }

	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<"  ";
	}
	return 0;
}
