class Solution {
public:
    bool isalpha(char c)
    {
        
        if((c>='A'&&c<='Z')||(c>='0'&&c<='9')||(c>='a'&&c<='z'))
            return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        int i=0,j=n-1;
        string b="";
        string c="";
        
        while(i<n&&j>-1)
        {
            if(isalpha(s[i]))
                b+=tolower(s[i]);
            if(isalpha(s[j]))
                c+=tolower(s[j]);
            i++;
            j--;
        }
        return b==c;
    }
};