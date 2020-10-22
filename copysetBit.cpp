#include<bits/stdc++.h>
using namespace std;

void cpyBit(int &x,int y,int l,int r)
{
	// l and r must be between 1 to 32 
	if(l<1 || r>32)
		return;

	/* Method 1
	for(int i=l;i<=r;i++)
	{
		//Find mask(A number whose 
       // only set bit is at i'th position)
		int mask=1<<(i-1);

		// If i'th bit is set in y, set i'th 
       // bit in x also. 
		if(y&mask)
			x=x|mask;
	}
	*/
	//Method 2
	//first take m1 as 1 which means bit at position 1 will be 1.
	//Then left shift the set bit by (r-l+1)
	//Then subtract 1 which will offset the set bit and set all offset bits right to the set bit.
	//Then left shift the bits by (l-1) and take & with y then or with x.
	//Reason for that is we need to find the bits given in range then just do an or with other element
	int masklength=(1<<(r-l+1))-1;
	int mask = (masklength<<(l-1))&y;
	x=x|mask;
}


int main()
{
	int x,y,l,r;
	cin>>x>>y>>l>>r;
	cpyBit(x,y,l,r);
	cout<<x;
}