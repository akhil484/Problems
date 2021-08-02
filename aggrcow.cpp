#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int check(long long mid, vector<long long> a,long long c)
{
	long long cp=1;
	long long last_position=a[0];
	for(int i=1;i<a.size();i++)
	{
		if(a[i]-last_position>=mid)
		{
			++cp;
			if(cp==c)
				return 1;
			last_position=a[i];
		}
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n,c,num,mid;
		cin>>n>>c;
		vector<long long> a;
		for(int j=0;j<n;j++)
		{
			cin>>num;
			a.push_back(num);
		}
		
		sort(a.begin(),a.end());
		long long l=a[0],h=a[n-1],dis=0;
		while(l<=h)
		{
			mid=l+(h-l)/2;
			if(check(mid,a,c)==1)
			{
				l=mid+1;
				dis=mid;
			}
			else
			{
				h=mid-1;
			}
		}
		cout<<dis<<endl;
	}
	return 0;
}
