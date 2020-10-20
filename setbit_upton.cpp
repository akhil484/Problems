#include <iostream>
using namespace std;

int raisepowerlessthan_n(int n)
{
    int x=0;
    while((1<<x)<=n)
    {
        x++;
    }
    return x-1;
}
int checksetbit(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    
    int x=raisepowerlessthan_n(n);
    int setbitin2raise_x=(x*(1<<(x-1)));
    int extrabit=(n-(1<<x)+1);
    int rem = (n-(1<<x));
    return setbitin2raise_x+extrabit+checksetbit(rem);
}


int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int n;
	    cin>>n;
	    int count = checksetbit(n);
	    cout<<count<<endl;
	}
	return 0;
}
