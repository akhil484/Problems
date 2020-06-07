//Print the reverse of a given string using recursion
//Time complexity O(n)

#include<iostream>
#include<string>
using namespace std;

void rev_a_string(string st, int len, int i)
{
	if(i == len-1)
	{
		cout<<st[i];
		return;
	}
	rev_a_string(st,len,i+1);
	cout<<st[i];
}

int main()
{
	int len;
	string st;
	cout<<"Enter string"<<" ";
	getline(cin,st);
	len=st.length();
	rev_a_string(st,len,0);
}