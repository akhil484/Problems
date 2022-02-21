class Solution {
    private:
    int dp[16384]={[0 ... 16383] = -1};
public:
    int calculatesum(vector<int>& nums1, vector<int>& nums2, int index, int mask)
    {
        if(index>=nums1.size())
            return 0;
        if(dp[mask]!=-1)
            return dp[mask];
        int ans=INT_MAX;
        for(int j=0;j<nums2.size();j++)
        {
            if((mask>>j)&1)
                continue;
            int new_mask = (mask|(1<<j));
            ans = min(ans,(nums1[index]^nums2[j])+calculatesum(nums1,nums2,index+1,new_mask));
        }
        return dp[mask]=ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        return calculatesum(nums1,nums2,0,0);
    }
};