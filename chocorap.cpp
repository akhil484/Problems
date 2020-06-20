#include<iostream>
using namespace std;

int choc(int initial,int wrap)
{
	if(initial/wrap==0)
		return 0;

	return (initial/wrap)+choc(initial/wrap+(initial%wrap),wrap);
}

int main()
{
	int chocolate,price,wrap;
	cin>>chocolate>>price>>wrap;
	int initial=chocolate/price,total=0;
	total=initial + choc(initial,wrap);
	cout<<total;
}