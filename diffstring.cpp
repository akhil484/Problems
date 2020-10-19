#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int sum=0,max_sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(s[i]=='0'?1:-1);
		if(sum<0)
			sum=0;
		max_sum = max(sum,max_sum);
	}
	if(max_sum==0)
		cout<<-1<<endl;
	else
		cout<<max_sum<<endl;

}