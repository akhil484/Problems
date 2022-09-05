class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used=0,i=0,j=0,res=1;
        for(i=0;i<nums.size();i++)
        {
            while((used&nums[i])!=0)
                used^=nums[j++];
            used|=nums[i];
            res=max(res,i-j+1);
        }
        return res;
    }
};