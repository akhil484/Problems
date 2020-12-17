class Solution {
public:
    string reorganizeString(string S) {
        string res="";
        int n = S.length();
        int count[26]={0};
        for(int i=0;i<n;i++)
        {
            count[S[i]-'a']++;
        }
        while(res.length()<S.length())
        {
            char prev = res.length()>0 ? res.back() : ' ';
            int idx=-1;
            for(int i=0;i<26;i++)
            {
                if((i+'a')==prev || count[i]==0)
                    continue;
                if(idx<0 || count[i]>count[idx])
                    idx=i;
            }
            if(idx<0)
                return "";
            else
            {
                --count[idx];
                res+=(idx+'a');
            }
                
        }
        return res;
    }
};
