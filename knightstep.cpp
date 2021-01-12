// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution {
public:
bool issafe(int x, int y, int N) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
} 
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	     int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
  
    // queue for storing states of knight in board 
    queue<pair<int,int>> q; 
    q.push(make_pair(KnightPos[0],KnightPos[1]));
    // push starting position of knight with 0 distance 
     
  
    int visit[N + 1][N + 1]; 
  
    // make all cell unvisited 
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            visit[i][j] = -1; 
    visit[q.front().first][q.front().second]=0;
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        for(int i=0;i<8;i++)
        {
            int cx=curX+dx[i];
            int cy=curY+dy[i];
            if(issafe(cx,cy,N)&&visit[cx][cy]==-1)
            {
                visit[cx][cy]=visit[curX][curY]+1;
                q.push({cx,cy});
            }
            if(cx==TargetPos[0] && cy==TargetPos[1])
                return visit[cx][cy];
        }
        q.pop();
    }
    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
