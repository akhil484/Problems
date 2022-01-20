class Solution {
public:
//     void dfs(string s, string t, string res, int &c, int index)
//     {
        
//         if(res.length()==t.length())
//         {    c+=res==t;
//             return;
//         }
//         if(index>=s.length())
//             return;
//         for(int i=index;i<s.length();i++)
//         {
//             dfs(s,t,res+s[i],c,i+1);
//             dfs(s,t,res,c,i+1);
//         }
//     }
    
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int> (n + 1, 0));
        for(int j=0;j<=n;j++)
            dp[0][j]=1;
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=m;i++)
            {
                dp[i][j] = dp[i][j-1]+(t[i-1]==s[j-1]?dp[i-1][j-1]:0);
            }
        }
        return dp[m][n];
    }
};