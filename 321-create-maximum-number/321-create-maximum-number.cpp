class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        for(int i=0;i<nums.size();i++)
        {
            while(!stack.empty()&&stack.back()<nums[i]&&stack.size()-1+nums.size()-i>=k)
                stack.pop_back();
            if(stack.size()<k)
                stack.push_back(nums[i]);
        }
        return stack;
    }
    
    bool greater(vector<int>& nums1, vector<int>& nums2, int a, int b)
    {
        while(a<nums1.size()||b<nums2.size())
        {
            if(a>=nums1.size())
                return false;
            else if(b>=nums2.size())
                return true;
            else if(nums1[a]<nums2[b])
                return false;
            else if(nums1[a]>nums2[b])
                return true;
            else
                ++a,++b;
        }
        return true;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i=0;i<=k;i++)
        {
            int j = k-i;
            if(i>nums1.size()||j>nums2.size())
                continue;
            vector<int> max1 = mostCompetitive(nums1,i);
            vector<int> max2 = mostCompetitive(nums2,j);
            vector<int> merged;
            int a=0,b=0;
            while(a<max1.size()||b<max2.size())
            {
                if(a>=max1.size())
                    merged.push_back(max2[b++]);
                else if(b>=max2.size())
                    merged.push_back(max1[a++]);
                else if(max1[a]<max2[b])
                    merged.push_back(max2[b++]);
                else if(max1[a]>max2[b])
                    merged.push_back(max1[a++]);
                else
                {
                    if(greater(max1,max2,a,b))
                        merged.push_back(max1[a++]);
                    else
                        merged.push_back(max2[b++]);
                }
            }
            if(merged>ans)
                ans=merged;
        }
        return ans;
    }
};