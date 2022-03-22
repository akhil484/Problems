class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s,t,r;
        for(int i=0;i<n;i++)
        {
            r={arr[i]};
            for(int j:t)
                r.insert(j|arr[i]);
            t=r;
            for(int j:t)
                s.insert(j);
        }
        return s.size();
    }
};