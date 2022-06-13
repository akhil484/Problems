class Solution {
public:
    int xorOperation(int n, int start) {
        int xo=-1;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            nums[i] = start+2*i;
            if(xo==-1)
                xo=nums[i];
            else
                xo^=nums[i];
        }
        return xo;
    }
};