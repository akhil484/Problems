class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);
        // dp[i] means maximum points we can get at index i.
        // we will have two choices at index i -
        // (a) Include the current index-
        // dp[i] = include current index points + dp[next index after skipping question[i][1] elements]
        // (b)Skip this index-
        // maximum points we can get for dp[i + 1]
        for(int i=n-1;i>=0;i--)
        {
            int points = questions[i][0];
            int jump = questions[i][1];
            dp[i] = max(dp[i+1],points+dp[min(n,jump+i+1)]);
        }
        return dp[0];
    }
};