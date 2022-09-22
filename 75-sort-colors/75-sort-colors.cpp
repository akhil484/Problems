class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l, r, mid;
        l=mid=0;
        r=nums.size()-1;
        while(mid<=r)
        {
            if(nums[mid]==0)
            {
                int temp=nums[mid];
                nums[mid]=nums[l];
                nums[l]=temp;
                l++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else{
                int temp=nums[mid];
                nums[mid]=nums[r];
                nums[r]=temp;
                r--;
            }
        }
    }
};