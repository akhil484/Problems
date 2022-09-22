class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum,sum;
        max_sum=sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum = max(nums[i],nums[i]+sum);
            max_sum=max(max_sum,sum);
        }
        return max_sum;
    }
};