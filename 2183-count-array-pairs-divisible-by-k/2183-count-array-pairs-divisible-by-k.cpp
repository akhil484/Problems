class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long res=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int gcd1 = __gcd(nums[i],k);
            int gcd2=k/gcd1;
            if(gcd2==1)
                res+=i;
            else
            {
                for(auto it:mp)
                {
                    if(it.first%gcd2==0)
                    {
                        res+=it.second;
                    }
                }
            }
            mp[gcd1]++;
        }
        return res;
    }
};