class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right)
    {
        int inv_count=0;
        int j=mid;
        for(int i=left;i<=mid-1;i++)
        {
            while(j<=right&&nums[i]>2LL*nums[j])
                j++;
            inv_count+=(j-mid);
        }
        vector<int> temp;
        int i=left;
        j=mid;
        while(i<=mid-1&&j<=right)
        {
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else 
            {
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid-1)
            temp.push_back(nums[i++]);
        while(j<=right)
            temp.push_back(nums[j++]);
        for(int i=left;i<=right;i++)
            nums[i]=temp[i-left];
        return inv_count;
    }
    
    int mergeS(vector<int>& nums, int left, int right)
    {
        int inv_count=0;
        int mid;
        if(right>left)
        {
            mid=(left+right)/2;
            inv_count+=mergeS(nums,left,mid);
            inv_count+=mergeS(nums,mid+1,right);
            inv_count+=merge(nums,left,mid+1,right);
        }
        return inv_count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeS(nums,0,nums.size()-1);
    }
};