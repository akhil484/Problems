class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> count(101,0);
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        for(int i=1;i<=100;i++)
        {
            if(count[i]>0)
            {
                c+=(count[i]*(count[i]-1))/2;
            }
        }
        return c;
    }
};