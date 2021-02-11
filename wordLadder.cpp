class Solution {
public:
    bool onediff(string &curr_word,string &w)
    {
        if(curr_word.length()!=w.length())
            return false;
        int diff=0;
        for(int i=0;i<w.length();i++)
        {
            if(curr_word[i]!=w[i])
                ++diff;
            if(diff>1)
                return false;
        }
        return diff==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        queue<string> bfs;
        bfs.push(beginWord);
        visited.insert(beginWord);
        int res=0;
        while(!bfs.empty())
        {
            int len=bfs.size();
            for(int i=0;i<len;i++)
            {
                string curr_word=bfs.front();
                bfs.pop();
                if(curr_word==endWord)
                    return res+1;
                for(auto w:wordList)
                {
                    if(onediff(curr_word,w)&&visited.find(w)==visited.end())
                    {
                        bfs.push(w);
                        visited.insert(w);
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
