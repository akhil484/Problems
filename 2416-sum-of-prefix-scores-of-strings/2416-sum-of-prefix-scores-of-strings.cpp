class Solution {
public:
    struct Node{
        Node *links[26];
        int prefix = 0;
        
        bool containKey(char c)
        {
            return links[c-'a']!=NULL;
        }
        
        void insertKey(char c, Node *node)
        {
            links[c-'a'] = node;
        }
        
        Node *getNext(char c)
        {
            return links[c-'a'];
        }
        
        void increasePrefix()
        {
            prefix++;
        }
        
        int getPrefix()
        {
            return prefix;
        }
    };
    
    class Trie{
        Node *root;
        public:
        Trie()
        {
            root = new Node();
        }
        
        void insert(string word)
        {
            Node *node = root;
            for(int i=0;i<word.size();i++)
            {
                if(!node->containKey(word[i]))
                {
                    node->insertKey(word[i],new Node());
                }
                node = node->getNext(word[i]);
                node->increasePrefix();
            }
        }
        
        int getprefixsum(string word)
        {
            Node *node = root;
            int sum = 0;
            for(int i=0;i<word.size();i++)
            {
                if(node->containKey(word[i]))
                {
                    node = node->getNext(word[i]);
                    sum+=node->getPrefix();
                }
                
               
            }
            return sum;
        }
        
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie *node = new Trie();
        for(auto word:words)
        {
            node->insert(word);
        }
        vector<int> ans;
        for(auto word:words)
        {
            int sum = node->getprefixsum(word);
            ans.push_back(sum);
        }
        return ans;
    }
};