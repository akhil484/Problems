class Solution {
public:
    void findcomb(int ind, int target, vector<int>& candidates, vector<vector<int>>& res, vector<int>& ds)
    {
        if(target==0)
        {
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind&&candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            ds.push_back(candidates[i]);
            findcomb(i+1,target-candidates[i],candidates,res,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        findcomb(0,target,candidates,res,ds);
        return res;
    }
};
