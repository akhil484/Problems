#include<iostream>
#include<string>
using namespace std;

void per(string st,int start,int end)
{
	if(start==end)
	{
		cout<<st<<" ";
		return;
	}

	for(int i=start;i<=end;i++)
	{
		swap(st[start],st[i]);
		per(st,start+1,end);
		swap(st[start],st[i]);
	}
}

int main()
{
	string st;
	cin>>st;
	per(st,0,st.length()-1);
}