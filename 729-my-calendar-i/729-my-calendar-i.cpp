class MyCalendar {
    private:
    set<pair<int,int>> s;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = s.upper_bound({start,start});
        if(next!=s.end()&&(*next).second<end)
            return false;
        s.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */