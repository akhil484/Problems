class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> mp;
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            mp.clear();
            int lmax=0,same=1;
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<points.size();j++)
            {
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1==x2&&y1==y2)
                    same++;
                else if(x1!=x2)
                {
                    double slope = (double)(y2-y1)/(double)(x2-x1);
                    mp[slope]++;
                }
                else
                {
                    mp[INT_MAX]++;
                }
            }
            for(auto it:mp)
            {
                lmax = max(lmax,it.second);
            }
            ans=max(ans,lmax+same);
        }
        return ans;
    }
};