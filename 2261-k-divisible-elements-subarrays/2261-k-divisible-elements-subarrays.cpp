class Solution {
public:
    
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int c = 0;
            vector<int> temp;
            for(int j=i;j<n;j++)
            {
                temp.push_back(nums[j]);
                if(nums[j]%p==0)
                {
                    ++c;
                }
                if(c>k)
                    break;
                s.insert(temp);
            }
        }
        return s.size();
    }
};