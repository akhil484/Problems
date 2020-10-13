#include<bits/stdc++.h>
using namespace std;

int ps(int x,int n,int index)
{
	//Return value of "pow" function is float and subtracting a float from an integer will not guarantee correct value. 
	//That is why the value after subtracting is stored inside an int variable. 
	//If you write '(x - pow(index, n))' in place of 'value' while calling the function, it will give you an error
	//because subtract will start getting float values.
	int value = (x - pow(index, n));
	if(value<0)
    	return 0;
	else if(value==0)
    	return 1;
    
    else 
    	return ps(x,n,index+1) + ps(value,n,index+1);
}

int main()
{
	int x,n;
	cin>>x;
	cin>>n;
	int c=ps(x,n,1);
	cout<<c<<"\n";
	return 0;
}
