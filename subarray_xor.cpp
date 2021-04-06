int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int cnt=0;
    int xo=0;
    for(auto a:A)
    {
        xo=xo^a;
        if(xo==B)
            cnt++;
        if(mp.find(xo^B)!=mp.end())
        {
            cnt+=mp[xo^B];
        }
        mp[xo]+=1;
    }
    return cnt;
}
