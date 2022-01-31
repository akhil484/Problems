class Solution {
public:
    string serialize(vector<vector<int>>& mat) {
        string s;
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                s = s + to_string(mat[i][j]);
            }
            s = s + "#";
        }
        return s;
    }
    
    bool good(vector<vector<int>>& mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j])
                    return false;
            }
        }
        return true;
    }
    
    void flipneigh(vector<vector<int>>& mat, map<string,bool>& visited, queue<vector<vector<int>>>& q)
    {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                auto tmp=mat;
                tmp[i][j]=!tmp[i][j];
                if(i+1<m)   tmp[i+1][j] = !tmp[i+1][j];
                if(i-1>=0)   tmp[i-1][j] = !tmp[i-1][j];
                if(j+1<n)   tmp[i][j+1] = !tmp[i][j+1];
                if(j-1>=0)   tmp[i][j-1] = !tmp[i][j-1];
                auto s = serialize(tmp);
                if(!visited[s])
                {
                    visited[s]=true;
                    q.push(tmp);
                }
            }
        }
    }
    
    int minFlips(vector<vector<int>>& mat) {
        queue<vector<vector<int>>> q;
        int m=mat.size();
        int n=mat[0].size();
        int level = 0;
        map<string,bool> visited;
        q.push(mat);
        while(!q.empty())
        {
            int siz = q.size();
            while(siz--)
            {
                auto fron=q.front();
                q.pop();
                if(good(fron))
                    return level;
                flipneigh(fron,visited,q);
            }
            level++;
        }
        return -1;
    }
};