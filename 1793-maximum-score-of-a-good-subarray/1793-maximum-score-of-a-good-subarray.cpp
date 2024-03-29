class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int score = nums[k];
        int value = nums[k];
        int i=k,j=k;
        int n = nums.size();
        while(i>0||j<n-1)
        {
            
            if((i>0?nums[i-1]:0)<(j<n-1?nums[j+1]:0))
            {
                value = min(value,nums[++j]);
            }
            else
                value = min(value,nums[--i]);
            score = max(score,value*(j-i+1));
        }
        return score;
    }
};