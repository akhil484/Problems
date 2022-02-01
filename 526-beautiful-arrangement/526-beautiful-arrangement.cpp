class Solution {
public:
    int count = 0;
    bool seen[16]={};
    int dfs(int n, int pos=1)
    {
        if(pos>n)
        {
            return count++;
        }
        for(int i=1;i<=n;i++)
        {
            if(!seen[i]&&(i%pos==0||pos%i==0))
            {
                seen[i]=1;
                dfs(n,pos+1);
                seen[i]=false;
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