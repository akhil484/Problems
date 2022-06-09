class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<h){
            if(nums[l]<nums[h])
                return nums[l];
            
            int mid = (l+h)/2;
            if(nums[mid]>=nums[l])
                l=mid+1;
            else
                h=mid;
            
        }
        return nums[l];
    }
};