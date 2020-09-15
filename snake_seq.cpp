#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 4

void sequence(int a[M][N])
{
	int lookup[M][N];
	memset(lookup,0,sizeof(lookup));
	int max_len=0, max_row,max_col;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i||j)
			{
				if(i>0 && abs(a[i-1][j]-a[i][j])==1)
				{
					lookup[i][j] = max(lookup[i][j],lookup[i-1][j]+1);
					if(max_len<lookup[i][j])
					{
						max_len = lookup[i][j];
						max_row = i;
						max_col = j;
					}
				}
				if(j>0 && abs(a[i][j-1]-a[i][j])==1)
				{
					lookup[i][j] = max(lookup[i][j],lookup[i][j-1]+1);
					if(max_len<lookup[i][j])
					{
						max_len = lookup[i][j];
						max_row = i;
						max_col = j;
					}
				}
			}
		}
	}
	cout<<"Max length of Sequence is: "<<max_len<<endl;

}



int main()
{
	int a[M][M] = {{9,6,5,2},{8,7,6,5},{7,3,1,6},{1,1,1,7}};

	sequence(a);
}