#include<bits/stdc++.h>
using namespace std;

int calSq(int n)
{
	if(n==0)
		return 0;
	if(n<0)
		n*=-1;

	int x = n>>1; 		//get floor(n/2)
	//check for odd
	if(n&1)				//if odd then n=(2*x + 1) else n=2*x
	{
		
		return ((calSq(x)<<2) + (x<<2) + 1);
	}
	else
	{
		return (calSq(x)<<2);
	}
}


int anothercal(int n)
{
	if(n==0)
		return n;
	if(n<0)
	{
		n=-n;
	}
	int result=0,times=n;
	while(times>0)
	{
		int possibleshift=0,currtimes=1;
		while((currtimes<<1) <=times)
		{
			currtimes=currtimes<<1;
			++possibleshift;
		}
		result+=(n<<possibleshift);
		times-=currtimes;
	}
	return result;
}


int main()
{
	int n;
	cin>>n;
	cout<<calSq(n)<<"\n";
	cout<<anothercal(n)<<"\n";
	return 0;
}