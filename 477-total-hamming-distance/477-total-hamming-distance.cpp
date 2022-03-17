class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total=0 , n = nums.size();
        for(int i=0;i<32;i++)
        {
            int bitcount = 0;
            for(int j=0;j<n;j++)
            {
                bitcount += (nums[j]>>i)&1;
            }
            total+=bitcount*(n-bitcount);
        }
        return total;
    }
};