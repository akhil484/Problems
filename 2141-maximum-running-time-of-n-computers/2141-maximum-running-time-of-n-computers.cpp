class Solution {
public:
    bool possible(vector<int>& batteries, long long k, int n)
    {
        long long val = k*n;
        for(int i=0;i<batteries.size();i++)
        {
            val -=min((long long)batteries[i],k);
        }
        return val<=0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(auto i:batteries)
        {
            sum+=i;
        }
        long long ans=0;
        long long l=0,h=sum;
        while(l<=h)
        {
            long long mid = l + (h-l)/2;
            if(possible(batteries,mid,n))
            {
                ans=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return ans;
    }
};