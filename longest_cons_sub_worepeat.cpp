class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int left=0,right=0;
        int n=s.size();
        int maxlen=0;
        while(right<n)
        {
            if(mp[s[right]]!=-1)
            {
                left=max(mp[s[right]]+1,left);
            }
            mp[s[right]]=right;
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};
