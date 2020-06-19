#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> a)
{
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return;
}

void fac(int num, int fact,vector<int> a,int prod)
{
	if(fact>num || prod>num)
		return;
	if(prod==num)
	{
		print(a);
		return;
	}

	for(int i=fact;i<num;i++)
	{
		if(i*prod>num)
			break;	
		if(num%i==0)
		{
			a.push_back(i);
			fac(num,i,a,prod*i);
			a.pop_back();
		}
	}
}


int main()
{
	int num;
	cin>>num;
	vector<int> a;
	int n=num/2;
	//int len=0;
	fac(num,2,a,1);
}