class Solution {
public:
    int f(string s, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=f(s,i+1,j-1,dp);
        else
            return dp[i][j]=1+min(f(s,i+1,j,dp),f(s,i,j-1,dp));
    }
    
    int minInsertions(string s) {
        // int n = s.length();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); 
        // return f(s,0,s.length()-1,dp);
        
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = s[i] == s[n - 1 - j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        return n - dp[n][n];
    }
};