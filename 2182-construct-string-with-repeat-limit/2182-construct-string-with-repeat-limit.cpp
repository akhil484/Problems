class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26,0);
        for(int i=0;i<s.length();i++)
            cnt[s[i]-'a']++;
        priority_queue<pair<int,int>,vector<pair<int,int>>> p;
        for(int i=0;i<26;i++)
        {
            if(cnt[i])
                p.push({i,cnt[i]});
        }
        string ans="";
        while(p.size())
        {
            int c = p.top().first;
            int freq = p.top().second;
            p.pop();
            if(ans.length()==0||(ans[ans.length()-1]-'a')!=c){
            int len=min(freq,repeatLimit);
            for(int i=0;i<len;i++)
                ans+=(c+'a');
            freq-=len;
            if(freq)
                p.push({c,freq});
            }
            else
            {
                if(p.size()==0)
                    break;
                int c1 = p.top().first;
                int freq1 = p.top().second;
                p.pop();
                freq1-=1;
                ans+=(c1+'a');
                if(freq1)
                    p.push({c1,freq1});
                p.push({c,freq});
            }
        }
        return ans;
    }
};