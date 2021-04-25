class Solution {
public:
    int myAtoi(string s) {
        int res=0,i=0;
        int sign=1;
        while(s[i]==' ')
            i++;
        if(s[i]=='-'||s[i]=='+')
        {
            sign=1-2*(s[i]=='-');
            i++;
        }
        while(s[i]>='0'&&s[i]<='9')
        {
            if(res>INT_MAX/10||(res==INT_MAX/10&&s[i]-'0'>7))           //Because INT_MAX has been divided by 10, so the tail vanishes. if the tail is 8 or 9, it will overflow.


            {
                if(sign==1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            res=res*10+(s[i++]-'0');
        }
        
        return res*sign;
    }
};
