#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
		string st;
		cin>>st;
		int n=st.length(),flag=0,temp=n/2;
		int a[26]={0};
		for(int i=0;i<n/2;i++)
		{
			a[st[i]-'a']+=1;
		}
		if(n%2!=0)
		    temp=n/2+1;
		for(int i=temp;i<n;i++)
		{
			a[st[i]-'a']-=1;
		}
		for(int i=0;i<26;i++)
		{
			if(a[i]!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
