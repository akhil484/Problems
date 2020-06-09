// Given two positive integers n and k, print all increasing sequences of length k such that the elements in every sequence are from first n natural numbers.
#include<iostream>
using namespace std;


void print(int arr[], int k)
{
	for(int i=0;i<k;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void rec_seq(int n, int k,int len,int arr[])
{
	if(len==k)
	{
		print(arr,k);
		return;
	}
	int i=(len==0)?1:arr[len-1]+1;
	len++;
	while(i<=n)
	{
		arr[len-1]=i;
		rec_seq(n,k,len,arr);
		i++;
	}
	len--;
}

int main()
{
	int n,k;
	cout<<"Enter the value of n and k"<<"\n";
	cin>>n>>k;
	int arr[k];
	int len=0;
	rec_seq(n,k,len,arr);
	return 0;
}