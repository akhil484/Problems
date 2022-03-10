class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto r:redEdges)
        {
            graph[r[0]].push_back({r[1],0});
        }
        for(auto b:blueEdges)
        {
            graph[b[0]].push_back({b[1],1});
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        vector<vector<int>> cost(n, vector<int>(2,-1));
        cost[0]={0,0};
        while(!q.empty())
        {
            int node = q.front().first;
            int color1 = q.front().second;
            q.pop();
            for(auto it:graph[node])
            {
                if(color1==it.second||cost[it.first][it.second]!=-1)
                    continue;
                cost[it.first][it.second] = 1+cost[node][color1];
                q.push({it.first,it.second});
            }
        }
        vector<int> res;
        for(auto c:cost)
        {
            int v = c[1];
            if(v==-1||(c[0]<v&&c[0]!=-1))
                v=c[0];
            res.push_back(v);
        }
        return res;
    }
};