class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
//         bool dp[n][n];
//         memset(dp,0,sizeof(dp));
//         int max_len=1;
//         // All substrings of length 1 
//         // are palindromes 
//         for(int i=0;i<n;i++)
//             dp[i][i]=true;
//         int start=0;
        
//         // check for sub-string of length 2
//         for(int i=0;i<n-1;i++)
//         {
//             if(s[i]==s[i+1])
//             {
//                 dp[i][i+1]=true;
//                 start=i;
//                 max_len=2;
//             }
//         }
//         // check for sub-string of length greater than 2
//         for(int k=3;k<=n;++k)
//         {
//             for(int i=0;i<(n-k+1);++i)
//             {
//                 int j=i+k-1;
//                 if(dp[i+1][j-1] && s[i]==s[j])
//                 {
//                     dp[i][j]=true;
//                     if(k>max_len)
//                     {
//                         max_len=k;
//                         start=i;
//                     }
//                 }
//             }
//         }
//         cout<<s.substr(start,max_len)<<endl;
        
        int start=0,max_len=1;
        int high,low;
        for(int i=1;i<n;i++)
        {
            low=i-1;
            high=i;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1>max_len)
                {
                    max_len=high-low+1;
                    start=low;
                }
                --low;
                ++high;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1>max_len)
                {
                    max_len=high-low+1;
                    start=low;
                }
                --low;
                ++high;
            }
        }
       // cout<<s.substr(start,2)<<endl;
        return s.substr(start,max_len);
    }
};
