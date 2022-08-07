class Solution {
public:
    bool validPartition(vector<int>& nums) {
       int n = nums.size();
        if(n==2) return nums[0] == nums[1];
        vector<int> dp(n+1);
        dp[0] = true;
        
        dp[1] = false;
        if(nums[0]==nums[1]){
            dp[2] = true;
        }
        if((nums[0]==nums[1] && nums[2]==nums[1])|| (nums[0]-nums[1]==-1 && nums[2]-nums[1]==1))
            dp[2] = true;
    
        for(int i=3;i<=n;i++)
        {
            bool ans=false;
            if(nums[i-1]==nums[i-2])
                ans=ans||dp[i-2];
            if(nums[i-1]==nums[i-2]&&nums[i-2]==nums[i-3])
                ans=ans||dp[i-3];
            if(nums[i-1]-nums[i-2]==1&&nums[i-2]-nums[i-3]==1)
                ans=ans||dp[i-3];
            dp[i]=ans;
        }
        return dp[n];
    }
};