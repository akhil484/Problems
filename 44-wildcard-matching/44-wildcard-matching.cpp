class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<bool> prev(m+1,false);       //0th row 
        vector<bool> cur(m+1,false);        //1st row
        
        prev[0] = true;
        
        for(int j=1;j<=m;j++)
        {
            bool flag=true;
            for(int i=0;i<j;i++)
            {
                if(p[i]!='*')
                {
                    flag=false;
                    break;
                }
            }
            prev[j] = flag;
        }
        
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=m;j++)
            {
                cur[0] = false;
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    cur[j] = prev[j-1];
                else if(p[j-1]=='*')
                    cur[j] = prev[j]||cur[j-1];
                else
                    cur[j]=false;
            }
            prev=cur;
        }
        return prev[m];
    }
};