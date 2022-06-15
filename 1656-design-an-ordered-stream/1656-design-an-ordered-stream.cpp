class OrderedStream {
public:
    int counter=0;
    vector<string> ans;
    OrderedStream(int n) {
        ans.resize(n," ");
    }
    
    vector<string> insert(int idKey, string value) {
        ans[idKey-1] = value;
        vector<string> chunk;
        int i=idKey-1;
        int n = ans.size();
        while(counter<n&&ans[counter]!=" ")
        {
            chunk.push_back(ans[counter]);
            counter++;
        }
        return chunk;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */