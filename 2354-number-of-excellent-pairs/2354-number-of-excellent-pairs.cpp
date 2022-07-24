class Solution {
public:
    int countBits(int n)
    {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long cnt[30] = {}, res = 0;
        for(int n:unordered_set<int>(begin(nums), end(nums)))
        {
            int bits = countBits(n);
            ++cnt[bits];
        }
        for(int i=1;i<30;i++)
        {
            for(int j=1;j<30;j++)
            {
                if(i+j>=k)
                    res+=cnt[i]*cnt[j];
            }
        }
        return res;
    }
};