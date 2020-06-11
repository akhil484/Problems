#include<bits/stdc++.h>
using namespace std;

void lexo(string st, int i,string output)
{
	if(i==st.length())
	{
		return;
	}
	cout<<output<<" ";
	for(int j=i+1;j<st.length();j++)
	{
		output+=st[j];
		lexo(st,j,output);
		output = output.erase(output.size() - 1); 
	}
}

int main()
{
	string st,output="";
	cout<<"Enter the string"<<" ";
	cin>>st;
	sort(st.begin(), st.end());
	lexo(st,-1,output);
}