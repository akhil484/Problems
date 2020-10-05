#include<bits/stdc++.h>
using namespace std;


int main()
{
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
		int n,k,x,y;
		cin>>n>>k>>x>>y;
		int covid[n];
		memset(covid,0,sizeof(covid));
		int temp = (x+k)%n;
		covid[temp] = 1;
		while(temp!=x && covid[y]==0)
		{
			temp = (temp+k)%n;
			covid[temp] = 1;
		}
		if(covid[y]==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
