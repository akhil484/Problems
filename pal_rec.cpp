#include<iostream>
using namespace std;

int rev(int n, int temp)
{
	if(n==0)
		return temp;
	temp = temp*10 + (n%10);
	return rev(n/10,temp);
}

int main()
{
	int res,num;
	cin>>num;
	res = rev(num,0);
	if(res == num)
	{
		cout<<res;
		cout<<"Palindrome";
	}
	else
	{
		cout<<res;
		cout<<"Not a Palindrome";
	}
}