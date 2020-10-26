class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = ((dividend<0) ^ (divisor<0))? -1:1;
        long long int n = abs(dividend);
        long long int m = abs(divisor);
        long long int q=0;
        long long int t=0;
        for(long long int i=31;i>=0;i--)
        {
            if(t+(m<<i)<=n)
            {
                t+=(m<<i);
                q=q+(1LL<<i);               //1LL converts one to long long because for higher values of i it will give wrong answer if 1 is int.(1*2^i)
            }
        }
        q=sign*q;
        if(q>INT_MAX)
            return INT_MAX;
        else
            return q;
    }
};
