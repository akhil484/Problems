class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int c=0;
        int index = (ruleKey == "type")?0:(ruleKey == "color")?1:2;
        int n=items.size();
        for(int i=0;i<n;i++)
        {
            if(items[i][index]==ruleValue)
                c++;
        }
        return c;
    }
};