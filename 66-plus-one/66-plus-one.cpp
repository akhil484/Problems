class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j=digits.size()-1;
        int c=0;
        while(true)
        {
            if(j<0)
            {
                digits.insert(digits.begin() , c);
                break;
            }
            int num = digits[j];
            num+=1;
            c=num/10;
            digits[j]=num%10;
            j--;
            if(c==0)
                break;
        }
        return digits;
    }
};