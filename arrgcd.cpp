#include<bits/stdc++.h>
using namespace std;
int *st;


int findgcd(int ss,int se,int qs,int qe,int si)
{
	if(ss>qe||se<qs)
		return 0;
	if(qs<=ss&&qe>=se)
		return st[si];		//given range is greater than the size of the array so we need top element
	int mid=ss+(se-ss)/2;
	return __gcd(findgcd(ss,mid,qs,qe,2*si+1),findgcd(mid+1,se,qs,qe,2*si+2));
}


int findRangeGcd(int ss,int se,int a[],int n)
{
	if(ss<0||se>n-1||ss>se)
	{
		cout<<"Invalid";
		return -1;
	}
	findgcd(0,n-1,ss,se,0);
}


int constructst(int a[],int ss,int se,int si)
{
	if(ss==se)
	{
		st[si]=a[ss];
		return st[si];
	}
	int mid = ss+(se-ss)/2;
	st[si]=__gcd(constructst(a,ss,mid,2*si+1),constructst(a,mid+1,se,2*si+2));
	return st[si];
}


int *constructsegmenttree(int a[],int n)
{
	int h=(int)(ceil(log2(n)));
	int size=2*(int)(pow(2,h))-1;
	st=new int[size];
	constructst(a,0,n-1,0);
}


int main()
{
	int a[] = {2, 3, 6, 9, 5}; 
    int n = sizeof(a)/sizeof(a[0]);
    constructsegmenttree(a,n);
    int l=1,r=3;
    cout << findRangeGcd(l, r, a, n) << "\n"; 
    return 0; 
}