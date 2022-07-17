class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        vector<int> ans;
       
        for(int i=0;i<n;i++)
        {
             priority_queue<pair<string,int>> pq;
            int k=queries[i][0],trim=queries[i][1];
            for(int j=0;j<m;j++)
            {
                
                if(pq.size()<k)
                {
                    string s = nums[j].substr(nums[j].size()-queries[i][1],queries[i][1]);
                    pq.push({s,j});
                }
                else
                {
                    if(nums[j].substr(nums[j].size()-queries[i][1],queries[i][1])<pq.top().first)
                    {
                        pq.pop();
                        pq.push({nums[j].substr(nums[j].size()-queries[i][1],queries[i][1]),j});
                    }
                }
                
            }
            ans.push_back(pq.top().second);
            
            
        }
        return ans;
    }
};