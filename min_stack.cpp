class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> s1;
    vector<int> s2;
    MinStack() {
        
    }
    
   void push(int x) {
	    s1.push_back(x);
	    if (s2.size()==0 || x <= getMin())  s2.push_back(x);	    
    }
    void pop() {
	    if (s1.back() == getMin())  s2.pop_back();
	    s1.pop_back();
    }
    int top() {
	    return s1.back();
    }
    int getMin() {
	    return s2.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
