class Solution {
public:
    int calcGCD(int a, int b)
    {
        if(b==0)
            return a;
        return calcGCD(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        for(int i:numsDivide)
            g=calcGCD(g,i);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()&&nums[i]<=g;i++)
        {
            if(g%nums[i]==0)
                return i;
        }
        return -1;
    }
};