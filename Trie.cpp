/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node *links[26];
    bool flag=false;
    bool containskey(char c)
    {
        return (links[c-'a']!=NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
private:
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
		root=new Node();
    }

    /** Inserts a word into the trie. O(len) */
    void insert(string word) {
		Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
            {
                node->put(word[i],new Node());
            }
            //moves to the reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. O(len)*/
    bool search(string word) {
		Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
                return false;
            else
                node=node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. O(len) */
    bool startsWith(string prefix) {
		Node *node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containskey(prefix[i]))
                return false;
            else
                node=node->get(prefix[i]);
        }
        return true;
    }
};
