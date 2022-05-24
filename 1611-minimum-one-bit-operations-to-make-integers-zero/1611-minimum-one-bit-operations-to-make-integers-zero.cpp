class Solution {
public:
    int minimumOneBitOperations(int n) {
        //It takes 2^n - 1 steps of operation for number 2^n.
        //For arbitrary number, it takes (2^n - 1) - StepOf(y) steps of operation for number 2^n + y.
        //DO for 1110 - 1000 + 110
         if (n <= 1)
        return n;
    int bit = 0;
    while ((1 << bit) <= n)
        bit++;
    return ((1 << bit) - 1) - minimumOneBitOperations(n - (1 << (bit-1)));
    }
};