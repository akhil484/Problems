class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int last[128] = {};
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=garbage[i].size();
            for(auto c:garbage[i])
                last[c] = i;
        }
        for(int i=1;i<travel.size();i++)
        {
            travel[i]+=travel[i-1];
        }
        for(auto c:"PGM")
        {
            if(last[c])
                res+=travel[last[c]-1];
        }
        return res;
    }
};