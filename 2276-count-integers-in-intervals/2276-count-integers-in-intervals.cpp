class CountIntervals {
public:
    set<pair<int,int>> st;
    int c;
    CountIntervals() {
        c=0;
        
    }
    
    
    void add(int left, int right) {
        auto it = st.upper_bound({left, INT_MIN});
        if(it!=st.begin()&&(--it)->second<left)
            ++it;
        while(it!=st.end()&&it->first<=right)
        {
            left=min(it->first,left);
            right=max(it->second,right);
            c-=(it->second-it->first+1);
            it=st.erase(it);
        }
        c+=right-left+1;
        st.insert({left,right});
    }
    
    int count() {
        return c;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */