//TC - O(m+n)

class Solution {
public:
    vector<int> calcP(string needle)
    {
        int n = needle.length();
        vector<int> res(n,0);
        int i=1,j=0;
        while(i<n)
        {
            if(needle[i]==needle[j])
            {
                res[i]=j+1;
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                {
                    j=res[j-1];
                }
                else
                {
                    res[i]=0;
                    i++;
                }
            }
        }
        return res;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> temp = calcP(needle);
        int n = haystack.length();
        int i=0,j=0;
        while(i<n&&j<needle.length())
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                    j=temp[j-1];
                else
                    i++;
            }
        }
        if(j==needle.length())
            return i-j;
        return -1;
    }
};