class Solution {
public:
    vector<int> dfs(vector<int>& edges, int dist, int node)
    {
        int n = edges.size();
        vector<int> m(n,-1);
        int i=node;
        while(i!=-1&&m[i]==-1)
        {
            m[i]=dist++;
            i=edges[i];
            if(i==node)
            {
                m[i]=dist;
                break;
            }
        }
        return m;
    }
    
    int longestCycle(vector<int>& e) {
         int res = -1;
    vector<pair<int, int>> memo(e.size(), {-1, -1});
    for (int i = 0; i < e.size(); ++i)
        for (int j = i, dist = 0; j != -1; j = e[j]) {
            pair<int,int> p = memo[j];
            if (p.first == -1)
                memo[j] = {dist++, i};
            else {
                if (p.second == i)
                    res = max(res, dist - p.first);
                break;
            }
        }
    return res;
    }
};