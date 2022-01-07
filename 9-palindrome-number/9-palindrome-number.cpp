class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        long long num=0,temp=x;
        while(x!=0)
        {
            num=num*10+(x%10);
            x=x/10;
        }
        return num==temp;
    }
};