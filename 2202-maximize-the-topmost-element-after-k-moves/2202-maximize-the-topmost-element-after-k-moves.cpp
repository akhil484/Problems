class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
       if(k==0)
           return nums[0];
        if(k%2!=0&&nums.size()==1)
            return -1;
        int n = nums.size();
        int i=0, max_ele=0;
        while(i<n&&i<k-1)
        {
            max_ele=max(max_ele,nums[i]);
            i++;
        }
        int ans=0;
        if(k<n)
            ans=nums[k];
        return max(max_ele,ans);
    }
};