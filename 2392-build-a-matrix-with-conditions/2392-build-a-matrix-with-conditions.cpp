class Solution {
public:
    
    vector<int> kahnalgo(int k, vector<vector<int>>& rc)
    {
        vector<int> indegree(k,0);
        vector<int> graph[k];
        for(auto x:rc){
            indegree[x[1]-1]++;
            graph[x[0]-1].push_back(x[1]-1);
        }
        
        
        queue<int> q;
        for(int i=0;i<k;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i:graph[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        return ans;
        
    }
    
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<int> row = kahnalgo(k,rc);
        if(row.size()!=k) return {};
        vector<int> col = kahnalgo(k,cc);
        if(col.size()!=k) return {};
        vector<int> m(k,0);
        for(int i=0;i<k;i++)
        {
            m[col[i]]=i;
        }
        for(int i=0;i<k;i++)
        {
            res[i][m[row[i]]] = row[i]+1;
        }
        return res;
    }
};