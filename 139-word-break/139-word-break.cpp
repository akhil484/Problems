class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }
        int n = s.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&st.find(s.substr(j,i-j))!=st.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};