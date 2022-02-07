class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        int max_bloom_time = INT_MIN;

        int n =plantTime.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int res=0;
        for(int i=0;i<v.size();i++)
        {
            res+=v[i].second;
            int bloomTime = res+v[i].first+1;
            max_bloom_time = max(max_bloom_time,bloomTime);
        }
        return max_bloom_time-1;
    }
};