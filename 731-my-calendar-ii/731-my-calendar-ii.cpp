class MyCalendarTwo {
    map<int,int> t;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        t[start]++;
        t[end]--;
        int activeEvents=0;
        for(auto it=t.begin();it!=t.end();it++)
        {
            activeEvents+=it->second;
            if(activeEvents>=3)
            {
                t[start]--;
                t[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */