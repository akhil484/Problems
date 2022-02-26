class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int res=0;
        unordered_set<int> st;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0)
                continue;
            if(st.find(freq[i])==st.end())
                st.insert(freq[i]);
            else
            {
                int delete_char = 0;
                while(st.find(freq[i])!=st.end())
                {
                    delete_char++;
                    freq[i]--;
                }
                if(freq[i]>0)
                    st.insert(freq[i]);
                res+=delete_char;
            }
        }
        return res;
    }
};