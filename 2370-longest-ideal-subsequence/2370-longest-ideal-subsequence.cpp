class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> res(26,0);
        int maxlen=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            int c = (s[i]-'a');
            int m=0;
            for(int b=max(0,c-k);b<=min(25,c+k);b++)
            {
                m=max(m,res[b]);
            }
            res[c]=1+m;
            
        }
        for(int i=0;i<26;i++)
        {
            maxlen=max(maxlen,res[i]);
        }
        return maxlen;
    }
};