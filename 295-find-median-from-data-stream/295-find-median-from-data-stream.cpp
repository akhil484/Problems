class MedianFinder {
public:
    priority_queue<double> pqmax;
        priority_queue<double,vector<double>,greater<double>> pqmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqmax.empty()||pqmax.top()>=num)
            pqmax.push((double)num);
        else
            pqmin.push((double)num);
        if((pqmax.size()-pqmin.size())==2)
        {
            double n = pqmax.top();
            pqmax.pop();
            pqmin.push(n);
        }
        if(pqmin.size()>pqmax.size())
        {
            pqmax.push(pqmin.top());
            pqmin.pop();
        }
    }
    
    
    double findMedian() {
        if(pqmax.size()-pqmin.size()==1)
        {
            
            return pqmax.top();;
        }
        else
            return (pqmax.top()+pqmin.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */