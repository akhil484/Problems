class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        vector<int> dp(n+1,0);
        int sum = 0,time=neededTime[0];
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                sum = sum + min(time,neededTime[i]);
                time = max(time,neededTime[i]);
            }
            else
                time = neededTime[i];

        }
        return sum;
    }
};