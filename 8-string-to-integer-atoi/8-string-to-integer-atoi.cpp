class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long res=0;
        while(s[i]==' ')
            i++;
        if(s[i]=='-'||s[i]=='+')
        {
            sign=1-2*(s[i]=='-');
            i++;
        }
        while(s[i]>='0'&&s[i]<='9')
        {
            res=res*10+(s[i]-'0');
            if(sign==-1&&sign*res<INT_MIN)
                return INT_MIN;
            if(sign==1&&sign*res>INT_MAX)
                return INT_MAX;
            i++;
        }
        
        return res*sign;
    }
};