class Solution {
public:
//     mask == 0 means we didn't use any number before
// i == 0 means we want to use 0 now
// mask == 0 && i== 0 means if we want to set 0 to current position, as a leading 0
// for example, if we have 1234,
// then we can set 0 to first positon, that is 0XXX, 0234, that's 234
// then we can also set 0 to second position, that is 00XX, 0012, that's 12
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