class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1&&nums[0]==val)
            return 0;
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[j]==val)
                j--;
            else if(nums[i]!=val)
                i++;
            else
            {
                nums[i]=nums[j];
                nums[j]=val;
                i++;
                j--;
            }
        }
        return i;
    }
};