class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        for(int i=0;i<columnTitle.size();i++)
        {
            sum*=26;
            sum+=columnTitle[i]-'A'+1;
        }
        return sum;
    }
};