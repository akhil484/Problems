class Solution {
public:
    long long appealSum(string s) {
        vector<int> last(26,0);
        int n = s.length();
        long long res=0;
        for(int i=0;i<n;i++)
        {
            last[s[i]-'a']=i+1;
            //count all substrings ending at i which contain charater l;
            //from all substrings we are picking no of a then b then c
            for(int l: last)
                res+=l;
        }
        return res;
    }
};