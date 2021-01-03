class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        if(n==0)
            return res;
        vector<int> ti=intervals[0];
        for(auto it:intervals)
        {
            if(it[0]<=ti[1])
            {
                ti[1]=max(it[1],ti[1]);
            }
            else
            {
                res.push_back(ti);
                ti=it;
            }
        }
        res.push_back(ti);
        return res;
    }
};
