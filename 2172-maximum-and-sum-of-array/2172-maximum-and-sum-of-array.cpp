class Solution {
    private:
        int f(int index, vector<int> &slotWt, vector<int>& nums, int numSlots,map<pair<int,vector<int>>,int> &dp)
        {
            if(index>=nums.size())
                return 0;
            if(dp.find({index,slotWt})!=dp.end())
                return dp[{index,slotWt}];
            int maxi=INT_MIN;
            for(int k=1;k<=numSlots;k++)
            {
                if(slotWt[k]<2)
                {
                    slotWt[k]++;
                    int ans = (nums[index]&k)+f(index+1,slotWt,nums,numSlots,dp);
                    slotWt[k]--;
                    maxi=max(ans,maxi);
                }
            }
            return dp[{index,slotWt}] = maxi;
        }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> slotWt(numSlots+1,0);
        map<pair<int,vector<int>>,int> dp;
        return f(0,slotWt,nums,numSlots,dp);
    }
};