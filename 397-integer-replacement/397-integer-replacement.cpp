class Solution {
public:
    
    int integerReplacement(int n) {
        int ans=0;
        while(n!=1)
        {
            if(n==3)
                return ans+=2;
             if (n == INT_MAX) return 32;
            else if(n%2==0)
            {
                n=n/2;
            }
            else if((n+1)%4==0)
                n++;
            else
                n--;
            ans++;
            
        }
        return ans;
    }
};