class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        
        if(l1+l2!=l3)
            return false;
        bool dp[l1+1][l2+1];
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
                dp[i][j]=false;
        }
        dp[0][0]=true;
        for(int i=1;i<=l1;i++)
        {
            if(s1[i-1]==s3[i-1])
                dp[i][0]=dp[i-1][0];
            else
                dp[i][0]=false;
        }
        for(int i=1;i<=l2;i++)
        {
            if(s2[i-1]==s3[i-1])
            {
                dp[0][i]=dp[0][i-1];
            }
            else
            {
                dp[0][i]=false;
            }
        }
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s1[i-1]==s3[i+j-1])
                    dp[i][j]=dp[i-1][j];
                if(s2[j-1]==s3[i+j-1])
                    dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
        return dp[l1][l2];
    }
};
