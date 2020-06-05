#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > board;
int N;
int is_valid(int i, int j)
{
	int k;
	for(k=0;k<N;k++)
	{
		if(board[i][k]==1 || board[k][j]==1)
			return 0;
	}

	for(k=0;k<N;k++)
	{
		for(int l=0;l<N;l++)
		{
			if((k+l) == (i+j) || (k-l) == (i-j))
			{
				if(board[k][l]==1)
					return 0;
			}
		}
	}
	return 1;
}
int queen(int index)
{
	if(index==N)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return 0;
	}
	for(int i=0;i<N;i++)
	{
			if(is_valid(index,i) && board[index][i]!=1)
			{
				board[index][i]=1;
				if(queen(index+1)==1)
					return 1;
				board[index][i]=0;
			}
		
	}
	return 0;
}

int main()
{
	cout<<"Enter the value of N"<<"\n";
	cin>>N;
	for(int i=0;i<N;i++)
	{
		vector<int> row;
		for(int j=0;j<N;j++)
		{
			row.push_back(0);
		}
		board.push_back(row);
	}
	queen(0);
	
	return 0;
}