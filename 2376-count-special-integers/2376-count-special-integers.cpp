class Solution {
public:
    int dp[11][2][1024];
   int util(string &str, int pos = 0, int tight = 1, int mask = 0)
   {
       if(pos==str.length())
       {
           return mask!=0;
       }
       if(dp[pos][tight][mask]!=-1)
           return dp[pos][tight][mask];
       int ans=0;
       if(tight==1)
       {
           for(int i=0;i<=str[pos]-'0';i++)
           {
               if(mask&(1<<i))
                   continue;
               int new_mask = (mask==0&&i==0?mask:(mask|(1<<i)));
               
               if(i==str[pos]-'0')
                   ans+=util(str,pos+1,1,new_mask);
               else
                   ans+=util(str,pos+1,0,new_mask);
               
           }
       }
       else
       {
           for(int i=0;i<=9;i++)
           {
               if(mask&(1<<i))
                   continue;
               int new_mask = (mask==0&&i==0?mask:(mask|(1<<i)));
               
              ans+=util(str,pos+1,0,new_mask);
               
           }
       }
       return dp[pos][tight][mask] = ans;
   }

    
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return util(s);
    }
};