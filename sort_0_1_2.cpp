class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low,mid,high;
        low=mid=0;
        high=n-1;
        while(high>=mid)
        {
            if(nums[mid]==0)
            {
                int temp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=temp;
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else
            {
                int temp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=temp;
                high--;
            }
        }
    }
};
