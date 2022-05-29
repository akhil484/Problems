class Solution {
public:
    int totalSteps(vector<int>& nums) {
         int n = nums.size(), res = 0;
        stack<int> st;
        vector<int> dp(n,0);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                dp[i] = max(++dp[i], dp[st.top()]);
                st.pop();
                res = max(res, dp[i]);
            }
            st.push(i);
        }
        return res;
    }
};