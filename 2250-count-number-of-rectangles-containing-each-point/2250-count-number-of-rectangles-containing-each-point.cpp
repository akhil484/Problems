class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
      vector<vector<int>> mp(101);
        for(auto &r:rectangles)
        {
            mp[r[1]].push_back(r[0]);
        }
        for(int i=0;i<101;i++)
        {
            sort(mp[i].begin(),mp[i].end());
        }
        int pz = points.size();
        vector<int> res(pz,0);
        for(int i=0;i<pz;i++)
        {
            int cnt = 0;
            for(int j=points[i][1];j<101;j++)
            {
                int num = end(mp[j])- lower_bound(begin(mp[j]),end(mp[j]),points[i][0]);
                cnt+=num;
            }
            res[i]=cnt;
        }
        return res;
    }
};