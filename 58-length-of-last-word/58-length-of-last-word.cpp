class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0,j=0,l=0;
        while(i<s.length()&&j<s.length())
        {
            
            while(i<s.length()&&s[i]==' ')
                i++;
            j=i;
            while(j<s.length()&&s[j]!=' ')
                j++;
            if(i<s.length()&&s[i]!=' ')
                l=j-i;
            i=j;
        }
        return l;
    }
};