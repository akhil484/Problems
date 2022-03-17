class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int step=0;
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            step++;
        }
        return right<<step;
    }
};