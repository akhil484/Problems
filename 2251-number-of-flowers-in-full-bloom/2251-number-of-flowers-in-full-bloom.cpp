class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start,end;
        for(auto f:flowers)
        {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        vector<int>res;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(auto t:persons)
        {
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            res.push_back(started - ended);
        }
        return res;
    }
};