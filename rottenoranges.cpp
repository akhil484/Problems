// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();
        int row[]={-1,0,0,1};
        int col[]={0,-1,1,0};
        queue<pair<int,int>>q;
        int ones=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    ones++;
                else if(grid[i][j]==2)
                    q.push(make_pair(i,j));
            }
        }
        int count=0;
        while(!q.empty())
        {
            int si=q.size();
            if(ones<=0)
                return count;
            count++;
            for(int i=0;i<si;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int X=x+row[k];
                    int Y=y+col[k];
                    if(X<0||X>r-1||Y<0||Y>c-1)
                        continue;
                    if(grid[X][Y]==1)
                    {
                        grid[X][Y]=2;
                        ones--;
                        q.push(make_pair(X,Y));
                    }
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
