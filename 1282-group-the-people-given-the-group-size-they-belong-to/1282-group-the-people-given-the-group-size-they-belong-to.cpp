class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> mp(n+1);

        for(int i=0;i<n;i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=1;i<=n;i++)
        {
            if(mp[i].size()==0)
                continue;
            int c=0;
            for(int j=0;j<mp[i].size();j++)
            {
                c++;
                temp.push_back(mp[i][j]);
                
                if(c==i)
                {
                    res.push_back(temp);
                    c=0;
                    temp.clear();
                }
            }
        }
        return res;
    }
};