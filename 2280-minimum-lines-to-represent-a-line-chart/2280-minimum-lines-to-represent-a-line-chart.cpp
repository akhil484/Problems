class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n==1||n==2)
            return n-1;
        sort(stockPrices.begin(),stockPrices.end());
        int c = 1;
        for(int i=2;i<n;i++)
        {
            long x1 = stockPrices[i][0],x2 = stockPrices[i-1][0],x3 = stockPrices[i-2][0];
            long y1 = stockPrices[i][1],y2 = stockPrices[i-1][1],y3 = stockPrices[i-2][1];
            long diff1 = (y3-y2)*(x2-x1);
            long diff2 = (y2-y1)*(x3-x2);
            if(diff1!=diff2)
            {
                c++;
            }
        }
        return c;
    }
};