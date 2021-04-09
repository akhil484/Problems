class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i=0,j=1;
        while(i<=j && j<nums.size())
        {
            if(nums[i]==nums[j])
                j++;
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
        
    }
};
