#include<iostream>
#include<math.h>
using namespace std;
int count;

void powers(int x, int n, int i)
{
	if(x>0 && x<2)
	{
		count++;
		return;
	}

	while(i<x/2)
	{
		int temp=x;
		x = x-pow(i,n);
		powers(x,n,i+1);
		x=temp;
		i++;
	}
}

int main()
{
	int x,n;
	cout<<"Enter the number and power"<<" ";
	cin>>x>>n;
	powers(x,n,1);
	cout<<count;

}