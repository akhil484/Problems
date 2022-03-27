class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1] and (i - ans) % 2 == 0) ans++;
        ans+=(nums.size() - ans) % 2; //if after deletion size is odd then delete one more element
        return ans;
    }
};