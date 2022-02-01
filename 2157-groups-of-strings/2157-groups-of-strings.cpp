class Solution {
public:
    int countGroups,largestGroup ;
vector<int> parent,sz;
    void unionf(int u,int v){
    int pu = findParent(u) ;
    int pv = findParent(v) ;
    
    if(pu==pv)
        return ;
    
    parent[pu] = pv ;
    sz[pv] += sz[pu] ;
    
    countGroups--;
    largestGroup = max(largestGroup, sz[pv]) ;
}



    int findParent(int u){
    if(u==parent[u])
        return u ;
    return parent[u] = findParent(parent[u]) ;
}
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        countGroups = n;
        largestGroup=1;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            sz.push_back(1);
        }
        unordered_map<int,int> present;
    int bitMask =0,bitMaskNew ;
    
    for(int i=0;i<words.size();i++){
        
        bitMask=0;
        for(auto& ch:words[i])
            bitMask |= (1<<(ch-'a')) ;
        
        for(int b=0;b<26;b++){
        
            bitMaskNew = (bitMask|(1<<b)) ;
            if(present.count(bitMaskNew))
                unionf(present[bitMaskNew],i) ;
            present[bitMaskNew] = i;
        }
        
    }
    
    return {countGroups,largestGroup} ;
    }
};