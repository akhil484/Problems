//Given a positive integer n, print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.
//It means that at any point 0 can not be more than 1 while filing the array of adding in a string.
#include<iostream>
using namespace std;

void print(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i];
	cout<<" ";
}

void onezero(int n, int a[], int zero, int one, int len)
{
	if(zero>one)
		return;

	if(len==n)
	{
		print(a,n);
		return;
	}

	a[len] = 1;
	onezero(n,a,zero,one+1,len+1);
	a[len] = 0;
	onezero(n,a,zero+1,one,len+1);
}

int main()
{
	int n;
	cout<<"Enter the value of n"<<" ";
	cin>>n;
	int one=0,zero=0;
	int a[n];
	onezero(n,a,zero,one,0);
}