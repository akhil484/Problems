class Solution {
public:
    int find(int x, vector<int> &union_find)
    {
        if(x==union_find[x])
            return x;
        return union_find[x] = find(union_find[x],union_find);
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> union_find(26,0);
        for(int i=0;i<26;i++)
            union_find[i]=i;
        int n = equations.size();
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
                union_find[find(equations[i][0]-'a',union_find)] = find(equations[i][3]-'a', union_find);
        }
        for(string e:equations)
        {
            if(e[1]=='!'&&(find(e[0]-'a',union_find)==find(e[3]-'a',union_find)))
                return false;
        }
        return true;
    }
};