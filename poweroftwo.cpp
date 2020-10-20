#include <iostream>
using namespace std;

int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    long long int n;
	    cin>>n;
	    if(n==0)
	        cout<<"NO"<<"\n";
	    else if((n&(n-1))==0)
	        cout<<"YES"<<"\n";
	    else
	        cout<<"NO"<<"\n";
	}
	return 0;
}
