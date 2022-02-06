class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        // long long res=n;
        // vector<int> v;
        // for(auto it:s)
        // {
        //     if(it=='0')
        //         v.push_back(-1);
        //     else
        //         v.push_back(1);
        // }
        // int mini=0;
        // int sum=0;
        // for(auto it:v)
        // {
        //     sum = min(it,sum+it);
        //     mini=min(mini,sum);
        // }
        // return n+mini;
        vector<int> dp(n,0);
        dp[n-1] = s[n-1]=='0'?0:1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
                dp[i]=dp[i+1];
            else
            {
                dp[i]=2+dp[i+1];
                dp[i]=min(dp[i],n-i); 
            }
        }
        int ans=dp[0];
        for(int i=0;i<n-1;i++){
            ans=min(ans,i+1+dp[i+1]); 
        }
        ans=min(ans,n); 
        return ans;
    }
};