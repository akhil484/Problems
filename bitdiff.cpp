#include <iostream>
using namespace std;

int main() {
	//code
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++)
	{
	    int a,b;
	    cin>>a>>b;
	    int n=a^b;
	    int count=0;
	    while(n)
	    {
	        count++;
	        n&=(n-1);
	    }
	    cout<<count<<"\n";
	}
	return 0;
}
