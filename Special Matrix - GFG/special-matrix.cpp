// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    int calc(vector<vector<int>> &dp, int n, int m)
    {
        for(int i=0;i<n;i++)
        {
            if(dp[i][0]==0)
                dp[i][0]=1;
            else 
                break;
        }
        for(int i=1;i<m;i++)
        {
            if(dp[0][i]==0)
                dp[0][i]=1;
            else 
                break;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(dp[i][j]==-1)
                    continue;
                if(dp[i-1][j]>0)
                    dp[i][j] = (dp[i][j]+dp[i-1][j])%1000000007;
                if(dp[i][j-1]>0)
                    dp[i][j] = (dp[i][j]+dp[i][j-1])%1000000007;
            }
        }
        
        return dp[n-1][m-1]>0?dp[n-1][m-1]:0;
    }

	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    vector<vector<int>>dp(n,vector<int>(m,0));
	    for(int i=0;i<blocked_cells.size();i++)
	    {
	        dp[blocked_cells[i][0]-1][blocked_cells[i][1]-1] = -1;
	    }
	    if(dp[0][0]==-1)
	        return 0;
	    
	    return calc(dp,n,m);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends