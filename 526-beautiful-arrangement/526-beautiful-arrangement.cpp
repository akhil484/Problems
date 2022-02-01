class Solution {
public:
    int count = 0;
    int seen=0;
    int dfs(int n, int pos=1)
    {
        if(pos>n)
        {
            return count++;
        }
        int bit;
        for(int i=1;i<=n;i++)
        {
            bit = 1<<i;
            if(!(seen&bit)&&(i%pos==0||pos%i==0))
            {
                seen^=bit;
                dfs(n,pos+1);
                seen^=bit;
            }
        }
        return count;
    }
    int countArrangement(int n) {
        if(n<4)
            return n;
        return dfs(n);
    }
};