class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            int c=0, r=queries[i][2]*queries[i][2];
            for(int j=0;j<points.size();j++)
            {
                c += (points[j][1]-queries[i][1])*(points[j][1]-queries[i][1])+(points[j][0]-queries[i][0])*((points[j][0]-queries[i][0]))<=r;
            }
            res[i]=c;
        }
        return res;
    }
};