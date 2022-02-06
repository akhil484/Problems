class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        long long res=n;
        vector<int> v;
        for(auto it:s)
        {
            if(it=='0')
                v.push_back(-1);
            else
                v.push_back(1);
        }
        int mini=0;
        int sum=0;
        for(auto it:v)
        {
            sum = min(it,sum+it);
            mini=min(mini,sum);
        }
        return n+mini;
    }
};