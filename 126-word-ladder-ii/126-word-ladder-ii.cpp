class Solution {
public:
    void getAdjacent(string& str, unordered_set<string>& wordSet, vector<string>& adjacent)
    {
        for(int i=0;i<str.size();i++)
        {
            char org = str[i];
            for(char c='a';c<='z';c++)
            {
                str[i]=c;
                if(wordSet.find(str)!=wordSet.end())
                    adjacent.push_back(str);
            }
            str[i]=org;
        }
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for(auto w:wordList)
        {
            if(w!=beginWord)
                wordSet.insert(w);
        }
        if(wordSet.find(endWord)==wordSet.end())
            return {};
        vector<vector<string>> res;
        bool found=false;
        queue<vector<string>> q;
        q.push({beginWord});
        int layer=1;
        unordered_set<string> searched;
        while(q.size()>0)
        {
            vector<string> v = q.front();
            if(v.size()>layer)
            {
                if(found)
                    break;
                for(auto item:searched)
                    wordSet.erase(item);
                searched.clear();
                layer++;
            }
            vector<string> adjacent;
            getAdjacent(v.back(),wordSet,adjacent);
            for(auto adj:adjacent)
            {
                vector<string> newVec = q.front();
                searched.insert(adj);
                // construct new vector
                newVec.push_back(adj);
                // if we have reached endWord, push the new vector to the back of the result
                if (adj == endWord) {
                    found = true;
                    res.push_back(newVec);
                } else {
                    // otherwise we push it to the q
                    q.push(newVec);   
                }
            }
            q.pop();
        }
        return res;
    }
};