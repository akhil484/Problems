class Solution {
public:
    void calc(vector<int>& nums, set<vector<int>> &s, vector<int> temp, int index)
    {
        if(temp.size()>=2)
        {
            s.insert(temp);
        }
        for(int i=index;i<nums.size();i++)
        {
            if(temp.size()==0||temp.back()<=nums[i])
            {
                temp.push_back(nums[i]);
                calc(nums,s,temp,i+1);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> s;
        calc(nums,s,temp,0);
        for(auto it:s)
            res.push_back(it);
        return res;
    }
};