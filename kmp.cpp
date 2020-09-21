#include<iostream>
#include<string.h>
using namespace std;

void cal_lps(char *pt, int *lps, int m)
{
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<m)
	{
		if(pt[i]==pt[len])
		{
			len+=1;
			lps[i] = len;
			i++;
		}
		else if(len==0)
		{
			lps[i]=0;
			i++;
		}
		else
		{
			len=lps[len-1];
		}
	}
}


void kmp(char *txt, char *pt)
{
	int m = strlen(pt);
	int n = strlen(txt);
	int lps[m];
	cal_lps(pt,lps,m);
	int i=0;
	int j=0;
	while(i<n)
	{
		if(pt[j]==txt[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"Found at "<<i-j<<endl;
		}
		else if(i<n && pt[j]!=txt[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}


int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pt[]= "ABABCABAB"; 
	kmp(txt,pt);
	return 0;
}