class Solution {
public:
    bool isunique(string str)
    {
        vector<int> freq(26,0);
        for(int i=0;i<str.length();i++)
        {
            if(freq[str[i]-'a'])
                return false;
            freq[str[i]-'a']++;
        }
        return true;
    }
    
    int maxLength(vector<string>& arr) {
        vector<string> temp;
        int ans=0;
        temp.push_back("");
        for(string a:arr)
        {
            if(!isunique(a))
                continue;
            vector<string> newvec;
            for(string t:temp)
            {
                string newstring = t+a;
                if(!isunique(newstring))
                    continue;
                newvec.push_back(newstring);
            }
            temp.insert(temp.end(),newvec.begin(),newvec.end());
        }
        for(string st:temp)
        {
            int len=st.length();
            ans=max(ans,len);
        }
        return ans;
    }
};