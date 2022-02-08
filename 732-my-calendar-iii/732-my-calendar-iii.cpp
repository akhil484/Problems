class MyCalendarThree {
    private:
    int k = 0;
    map<int,int> t;
public:
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        t[start]++;
        t[end]--;
        int activeEvents=0,temp=0;
        for(auto it=t.begin();it!=t.end();it++)
        {
            
            temp+=it->second;
            activeEvents=max(activeEvents,temp);
            // if(activeEvents>=3)
            // {
            //     t[start]--;
            //     t[end]++;
            //     return false;
            // }
        }
        return activeEvents;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */