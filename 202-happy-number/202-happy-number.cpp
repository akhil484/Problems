class Solution {
public:
    int next(int n)
    {
        int sum=0;
        while(n>0)
        {
            int x = n%10;
            sum+=x*x;
            n=n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow=next(n);
        int fast=next(next(n));
        while(fast!=slow)
        {
            slow=next(slow);
            fast=next(next(fast));
        }
        if(slow==1)
            return true;
        else
            return false;
    }
};