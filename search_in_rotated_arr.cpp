class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size();
        while(l<h)
        {
            int mid = (l+h)/2;
            double num = (nums[mid] < nums[0]) == (target < nums[0])
                   ? nums[mid]
                   : target < nums[0] ? -INFINITY : INFINITY;
            if(num<target)
            {
                l=mid+1;
            }
            else if(num>target)
                h=mid;
            else
                return mid;
        }
        
        return -1;
    }
};
