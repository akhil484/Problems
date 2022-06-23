class Solution {
public:
    
    int longestSubsequence(string s, int k) {
        int cnt=0;
        int val=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]-'0'==1&&val+(pow(2,cnt))<=k)
            {
                val=val+(pow(2,cnt));
                cnt++;
            }
            else if(s[i]-'0'==0)
                cnt++;
            
        }
        return cnt;
    }
};