#include <bits/stdc++.h>
using namespace std;
#define N 8
int board[N][N];
int r_move[8] = {2,1,-1,-2,2,1,-1,-2};
int c_move[8] = {1,2,2,1,-1,-2,-2,-1};
void print_sol()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<" "<<setw(2)<<board[i][j]<<" ";
		}		
		cout<<endl;
	}
	cout<<endl;
}
 int is_valid(int i, int j)
 {
 	if(i>=0 && i<N && j>=0 && j<N && board[i][j] == -1)
 	{
 		return 1;
 	}
 	return 0;
 }


int knight(int i, int j, int n)
{
	if(n == (N*N))
	{
		return 1;
	}

	
		//board[0][0] = 0;
		cout<<n<<endl;
		for(int k=0;k<8;k++)
		{
			int x = i+r_move[k];
			int y = j+c_move[k];
			if(is_valid(x,y)==1)
			{
				board[x][y] = n;
				if(knight(x,y,n+1)==1)
					return 1;
				board[x][y] = -1;
			}
		}
	
	

	return 0;
}

int main()
{
	int res;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j] = -1;
		}		
	}
	board[0][0] = 0;
	res = knight(0,0,1);
	if(res == 0)
	{
		cout<<"Solution does not exist"<<"\n";
	}
	else
		print_sol();
	return 0;
}