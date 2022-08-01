class Solution {
public:
    void dfs(vector<int>& edges, vector<int>& m, int dist, int i)
    {
        while(i!=-1&&m[i]==-1)
        {
            m[i]=dist++;
            i=edges[i];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res=-1;
        int min_dist = INT_MAX;
        int n = edges.size();
        vector<int> m1(n,-1);
        vector<int> m2(n,-1);
        dfs(edges,m1,0,node1);
        dfs(edges,m2,0,node2);
        for(int i=0;i<n;i++)
        {
            if(min(m1[i], m2[i]) >= 0 && max(m1[i],m2[i])<min_dist)
            {
                res=i;
                min_dist=max(m1[i],m2[i]);
            }
        }
        return res;
    }
};