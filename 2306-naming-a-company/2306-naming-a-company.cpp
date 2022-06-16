class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> st[26];
        for(string s:ideas)
        {
            st[s[0]-'a'].insert(s.substr(1));
        }
        
        long long res=0;
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {long long c1=0,c2=0;
                for(auto c:st[i])
                {
                    if(st[j].count(c)==0)
                        c1++;
                }
                for(auto c:st[j])
                {
                    if(st[i].count(c)==0)
                        c2++;
                }
                res+=c1*c2;
            }
        }
        return res*2;
    }
};