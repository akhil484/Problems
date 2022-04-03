class Solution {
public:
     bool calc(vector<int>& candies, long long k, long long mid)
    {
        int n = candies.size();
        int i=0;
        long long num=0;
        while(i<n)
        {
            
            num+=(candies[i])/mid;
            i++;
        }
        if(num>=k)
            return true;
        else
            return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int sum = 0;
        
        int n = candies.size();
        int ans=0;
        sort(candies.begin(),candies.end());
        int l=1,h=candies[n-1];
        
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(calc(candies,k,mid))
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