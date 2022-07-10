class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string ans="";
        int i=m,j=n;
        while(i>0&&j>0)
        {
            if(s[i-1]==t[j-1])
            {
                ans+=s[i-1];
                i--;
                j--;
                
            }
            else
            {
                if(dp[i-1][j]<dp[i][j-1])
                {
                    ans+=t[j-1];
                    j--;
                }
                else
                {
                    ans+=s[i-1];
                        i--;
                }
            }
        }
        
        
        while(i>0)
        {
            ans+=s[i-1];
            i--;
        }
            
        while(j>0)
        {
            ans+=t[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};