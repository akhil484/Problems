class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=0,exp=0;
        while(1)
        {
            try{
                if(nums.at(index)==target)
                    return index;
                else if(nums.at(index)<target)
                {
                    index=pow(2,exp);
                    exp+=1;
                }
                else
                    break;
            }
            catch(...)
            {
                break;
            }
        }
        int left=(index/2)+1;
        int right=index-1;
        int mid;
        while(left<=right)
        {
            
            try{
            mid=left+(right-left)/2;
            if(nums.at(mid)==target)
                return mid;
            else if(nums.at(mid)<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
            
        }
            catch(...)
        {
            right=mid-1;
        }
        
        }
        return -1;
    }
};
