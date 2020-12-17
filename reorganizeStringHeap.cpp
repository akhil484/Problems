class Solution {
public:
    
    struct Key 
{ 
    int freq; // store frequency of character 
    char ch; 
  
    // function for priority_queue to store Key 
    // according to freq 
    bool operator<(const Key &k) const
    { 
        return freq < k.freq; 
    } 
}; 
    
    string reorganizeString(string S) {
        string res="";
        int n = S.length();
        int count[26]={0};
        for(int i=0;i<n;i++)
        {
            count[S[i]-'a']++;
        }
        priority_queue< Key > pq; 
        for(char c='a';c<='z';c++)
        {
            if(count[c-'a'])
            {
                pq.push(Key { count[c-'a'], c});
            }
        }
        Key prev {-1, '#'} ; 
        while(!pq.empty())
        {
            Key k = pq.top();
            pq.pop();
            res+=k.ch;
            if(prev.freq>0)
                pq.push(prev);
            (k.freq)--;
            prev=k;
        }
        if(n==res.length())
            return res;
        else
            return "";
    }
};
