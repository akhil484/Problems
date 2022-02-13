class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans=LLONG_MAX;
        long long sum=0;
        int n = beans.size();
        for(int i=0;i<n;i++)
        {
            sum+=beans[i];
        }
        sort(beans.begin(),beans.end());
        for(int i=0;i<n;i++)
        {
            ans = min(ans, sum - ((n - i)*1LL * beans[i]));
        }
        return ans;
    }
};