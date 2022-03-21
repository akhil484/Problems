class Solution {
public:
    bool canPartition(vector<int>& nums, int mask, int start, int k, int currSum, int target)
    {
        if(k==1)
            return true;
        if(currSum>target||start>=nums.size())
            return false;
        if(currSum==target)
            return canPartition(nums, mask, 0, k-1, 0, target);
        bool isVisited = mask&(1<<start);
        if(isVisited)
            return canPartition(nums, mask, start+1, k, currSum, target);
        bool currEle = canPartition(nums, mask|(1<<start), start+1, k, currSum+nums[start], target);
        bool notcurrEle = canPartition(nums, mask, start+1, k, currSum, target);
        return currEle|notcurrEle;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%k!=0||k<=0||n<k)
            return false;
        int mask = 0;
        return canPartition(nums, mask, 0, k, 0, sum/k);
    }
};