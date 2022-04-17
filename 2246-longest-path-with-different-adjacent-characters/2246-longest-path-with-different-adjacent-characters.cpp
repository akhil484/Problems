class Solution {
public:
    int dfs(vector<vector<int>>& child, string& s, int &res, int i)
    {
        int path1 = 0,path2=0;
        for(auto j : child[i])
        {
            int cur = dfs(child,s,res,j);
            if(s[i]==s[j])
                continue;
            if(path2<cur)
                path2=cur;
            
            if(path2>path1)
                swap(path1,path2);
        }
        res=max(res,path1+path2+1);
        return path1+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=s.size(),res=0;
        vector<vector<int>> child(n,vector<int>());
        for(int i=1;i<n;i++)
        {
            child[parent[i]].push_back(i);
        }
        int val=dfs(child,s,res,0);
        return res;
    }
};