//Print all subsets of a given array
#include<iostream>
#include<vector>
using namespace std;
vector<int> res;
vector<int> arr;

void subset(int arr[], int l, int r, int sum=0)
{
	if(l>r)
	{
		cout<<sum<<" ";
		return;
	}

	subset(arr,l+1,r,sum+arr[l]);
	subset(arr,l+1,r,sum);
}

int main()
{
	int n,num;
	cout<<"Enter size of array";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	subset(arr,0,n-1);
	return 0;
}