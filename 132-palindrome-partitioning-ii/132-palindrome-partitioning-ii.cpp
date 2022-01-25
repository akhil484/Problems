class Solution {
public:
    bool p[2001][2001];
    int minCut(string s) {
        int len = s.length();
        int i,j,k;
        for(i=0;i<len;i++)
            p[i][i]=true;
        for(i=len-1;i>=0;i--)
        {
            for(j=i+1;j<len;j++)
            {
                if(j==i+1)
                {
                    if(s[i]==s[j])
                    {
                        p[i][j]=true;
                    }
                    else
                        p[i][j]=false;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(p[i+1][j-1])
                            p[i][j]=true;
                        else
                            p[i][j]=false;
                    }
                    else
                        p[i][j]=false;
                }
            }
        }
        int res[len];
        for(int i=0;i<len;i++)
        {
            if(p[0][i])
                res[i]=0;
            else
            {
                res[i]=INT_MAX;
                for(int j=1;j<=i;j++)
                {
                    if(p[j][i])
                        res[i]=min(res[i],res[j-1]+1);
                }
            }
        }
        return res[len-1];
    }
};