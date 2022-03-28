class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int pw = intLength%2 ==0?(intLength/2 - 1):(intLength/2);
        int start = pow(10,pw);
        vector<long long> res;
        for(auto q:queries)
        {
            string ans = to_string(start+q-1);
            string rev=ans;
            reverse(rev.begin(),rev.end());
            if(intLength%2==0)
                ans=ans+rev;
            else
            {
                ans=ans+rev.substr(1,rev.size()-1);
            }
            if(ans.length()==intLength)
                res.push_back(stoll(ans));
            else
                res.push_back(-1);
        }
        return res;
    }
};