#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n;
	    cin>>n;
	    int q=2,len=1,x=0,carry=0;
	    int arr[100000]={0};
	    arr[0]=1;
	    while(q<=n)
	    {
	        x=0;
	        carry=0;
	        while(x<len)
	        {
	            arr[x]=(arr[x]*q)+carry;
	            carry=arr[x]/10;
	            arr[x]=arr[x]%10;
	            
	            x++;
	        }
	        while(carry!=0)
	        {
	            arr[len]=carry%10;
	            carry=carry/10;
	            len++;
	        }
	        q++;
	    }
	    len--;
	    while(len>=0)
	    {
	        cout<<arr[len];
	        len--;
	    }
	    cout<<endl;
	}
	return 0;
}