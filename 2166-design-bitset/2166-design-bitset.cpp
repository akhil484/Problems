class Bitset {
    private:
    vector<int> res;
    int c;
    bool fl;
public:
    
    Bitset(int size) {
        res.resize(size,0);
        c=0;
        fl=false;
    }
    
    void fix(int idx) {
        if(!fl){
            if(res[idx]==0)
            {
                res[idx]=1;
                c++;
            }
        }
        else
        {
            if(res[idx]==1)
            {
                res[idx]=0;
                c++;
            }
        }
    }
    
    void unfix(int idx) {
        if(!fl){
            if(res[idx]==1)
            {
                res[idx]=0;
                c--;
            }
        }
        else
        {
            if(res[idx]==0)
            {
                res[idx]=1;
                c--;
            }
        }
    }
    
    void flip() {
        fl=!fl;
        c = res.size()-c;
    }
    
    bool all() {
        
        return c==res.size();
    }
    
    bool one() {
        return c>0;
    }
    
    int count() {
        return c;
    }
    
    string toString() {
       string ans="";
        if(!fl)
        {
            for(int i=0;i<res.size();i++)
                if(res[i]==0)
                    ans+='0';
                else
                    ans+='1';
        }
        else
        {
            for(int i=0;i<res.size();i++)
                if(res[i]==0)
                    ans+='1';
                else
                    ans+='0';
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */