class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        int l=0,h=46340;
        int res=0;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(m*m==x)
            {
                res = m;
                break;
              
            }
            else if(m*m>x)
                h=m-1;
            else if((m+1)>x/(m+1))
            {
                res = m;
                break;
            }
            else
                l=m+1;
        }
        return res;
    }
};