class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int> s;
        int res=0;
        for(int r:rolls)
        {
            s.insert(r);
            if(s.size()==k)
            {
                res++;
                s.clear();
            }
        }
        return res+1;
    }
};