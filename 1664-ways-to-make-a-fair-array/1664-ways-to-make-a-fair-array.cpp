class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int evenSum=0, oddSum=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                evenSum+=nums[i];
            }
            else
            {
                oddSum+=nums[i];
            }
        }
        int res=0, currEven=0, currOdd=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                if(currEven+(oddSum-currOdd)==currOdd+(evenSum-currEven-nums[i]))
                    res++;
                currEven+=nums[i];
            }
            else
            {
                if(currEven+(oddSum-currOdd-nums[i])==currOdd+(evenSum-currEven))
                    res++;
                currOdd+=nums[i];
            }
        }
        return res;
    }
};