class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(n<0)
            nn=-1*nn;
        while(nn)
        {
            if(nn%2==0)
            {
                nn=nn/2;
                x=x*x;
            }
            else
            {
                ans*=x;
                nn=nn-1;
            }
        }
        if(n<0)
            ans=(1.0)/ans;
        return ans;
    }
};
