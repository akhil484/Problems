#include<iostream>
using namespace std;

int min_func(int a,int b)
{
	return (a>b)?b:a;
}

int car_assemble(int *a, int *e, int *t, int *x,int n)
{
	int t1[n],t2[n];
	t1[0] = e[0]+*(a+(0*n)+0);					//a[0][0]
	t2[0]=e[1]+	*(a+(1*n)+0);					//a[1][0]
	for(int i=1;i<n;i++)
	{
		t1[i] = min(t1[i-1]+*(a+(0*n)+i), t2[i-1]+*(t+(1*n)+i)+*(a+(0*n)+i));

		t2[i] = min(t2[i-1]+*(a+(1*n)+i), t1[i-1]+*(t+(0*n)+i)+*(a+(1*n)+i));
	}

	return min(t1[n-1]+x[0],t2[n-1]+x[1]);
}


int main()
{
	int e[] = {10,12};
	int x[]={18,7};
	int a[][4]={{4,5,3,2},{2,10,1,4}};
	int t[][4]={{0,7,4,5},{0,9,2,8}};

	int n = sizeof(a[0])/sizeof(a[0][0]);			//divide the size of one row with size of an element in that row
	cout<<car_assemble(&a[0][0],e,&t[0][0],x,n);
	return 0;
}