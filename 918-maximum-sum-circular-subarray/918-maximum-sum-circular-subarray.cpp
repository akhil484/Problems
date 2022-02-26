class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
            curMax = max(nums[i]+curMax,nums[i]);
            maxSum = max(maxSum,curMax);
            curMin=min(nums[i]+curMin,nums[i]);
            minSum=min(minSum,curMin);
        }
        return maxSum>0?max(total-minSum,maxSum):maxSum;
    }
};